import sqlite3
from datetime import datetime
from models.horario import StatusAlarme
from threading import Timer
import locale
import unicodedata

def remover_acentos(texto):
    return ''.join(c for c in unicodedata.normalize('NFD', texto)
                   if unicodedata.category(c) != 'Mn').lower()

class HistoricoSirene:
    def __init__(self):
        self.ativo = False
        self.timers = []  # Armazena os timers ativos

    def ativar(self):
        self.ativo = True
        self.agendar_sirenes_do_dia()
        self.verificar_e_cadastrar_horarios()

    def desativar(self):
        self.ativo = False
        # Cancela todos os timers futuros
        for timer in self.timers:
            timer.cancel()
        self.timers.clear()
        print("🛑 Sistema de sirene desativado.")

    def agendar_sirenes_do_dia(self):
        agora = datetime.now()
        dia_semana = agora.strftime("%A").lower()

        conn = sqlite3.connect("sirene.db")
        cursor = conn.cursor()

        cursor.execute("SELECT id, horario FROM horarios WHERE dia = ?", (dia_semana,))
        alarmes_do_dia = cursor.fetchall()
        conn.close()

        for alarme_id, horario_str in alarmes_do_dia:
            horario = datetime.strptime(horario_str, "%H:%M").replace(
                year=agora.year, month=agora.month, day=agora.day
            )
            delta = (horario - agora).total_seconds()

            if delta > 0:
                timer = Timer(delta, self.acionar_sirene, args=[alarme_id, horario_str])
                timer.start()
                self.timers.append(timer)
                print(f"📅 Sirene para {horario_str} agendada em {int(delta)} segundos.")
            else:
                print(f"⏭️ Sirene das {horario_str} já passou para hoje.")

    def verificar_e_cadastrar_horarios(self):
        """Verifica se os horários do dia estão cadastrados no histórico e os insere caso não estejam."""
        locale.setlocale(locale.LC_TIME, 'pt_BR')
        agora = datetime.now()
        dia_semana = agora.strftime("%A").lower()
        dia_semana = remover_acentos(dia_semana.split('-')[0])
        print(f"Verificando horários para o dia: {dia_semana}")  # Log adicionado

        conn = sqlite3.connect("sirene.db")
        cursor = conn.cursor()

        # Busca os horários do dia atual
        cursor.execute("SELECT id, horario FROM horarios WHERE dia = ?", (dia_semana,))
        alarmes_do_dia = cursor.fetchall()
        print(f"Horários encontrados: {alarmes_do_dia}")  # Log adicionado

        for alarme_id, horario_str in alarmes_do_dia:
            # Verifica se o horário já está registrado no histórico
            cursor.execute("""
                SELECT COUNT(*) FROM historico
                WHERE horario_id = ? AND DATE(registrado_em) = DATE(?)
            """, (alarme_id, agora.strftime("%Y-%m-%d")))
            existe = cursor.fetchone()[0]

            if existe:
                print(f"⏩ O horário {horario_str} já está registrado no histórico.")
            else:
                # Se não estiver, registra como PENDENTE no histórico
                cursor.execute("""
                    INSERT INTO historico (horario_id, horario, status, registrado_em)
                    VALUES (?, ?, ?, ?)
                """, (alarme_id, horario_str, StatusAlarme.PENDENTE.value, agora.strftime("%Y-%m-%d %H:%M:%S")))
                print(f"📝 Horário {horario_str} cadastrado como PENDENTE no histórico.")

        conn.commit()
        conn.close()


    def acionar_sirene(self, alarme_id, horario_str):
        agora = datetime.now()
        try:
            print(f"🔔 Sirene acionada às {horario_str}")

            conn = sqlite3.connect("sirene.db")
            cursor = conn.cursor()

            # Registra a sirene acionada como SUCESSO
            cursor.execute("""
                INSERT INTO historico (horario_id, horario, status, registrado_em)
                VALUES (?, ?, ?, ?)
            """, (alarme_id, horario_str, StatusAlarme.SUCESSO.value, agora.strftime("%Y-%m-%d %H:%M:%S")))

            # Atualiza o status para CONCLUÍDO após a sirene ser acionada
            cursor.execute("""
                UPDATE historico
                SET status = ?
                WHERE horario_id = ? AND DATE(registrado_em) = DATE(?)
            """, (StatusAlarme.CONCLUIDO.value, alarme_id, agora.strftime("%Y-%m-%d")))

            conn.commit()
            conn.close()
        except Exception as e:
            print(f"❌ Erro ao acionar sirene às {horario_str}: {e}")
            conn = sqlite3.connect("sirene.db")
            cursor = conn.cursor()

            # Caso haja erro, registra o status como ERRO
            cursor.execute("""
                INSERT INTO historico (horario_id, horario, status, registrado_em)
                VALUES (?, ?, ?, ?)
            """, (alarme_id, horario_str, StatusAlarme.ERRO.value, agora.strftime("%Y-%m-%d %H:%M:%S")))

            conn.commit()
            conn.close()

