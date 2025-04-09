import threading
import time
import sqlite3
from services.arduino_service import acionar_sirene

def verificar_horarios():
    while True:
        conn = sqlite3.connect("sirene.db")
        cursor = conn.cursor()
        cursor.execute("SELECT horario FROM horarios")
        horarios = cursor.fetchall()
        conn.close()
        hora_atual = time.strftime("%H:%M")
        for horario in horarios:
            if horario[0] == hora_atual:
                acionar_sirene()
                time.sleep(60)
        time.sleep(30)

def iniciar_verificacao_horarios():
    thread = threading.Thread(target=verificar_horarios, daemon=True)
    thread.start()
    