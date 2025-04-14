from dados.fila_data import ultimas_chamadas
from models.guiche import Guiche
from services.senha_service import SenhaService

class GuicheService:
    def __init__(self, senha_service: SenhaService):
        self.senha_service = senha_service

    def chamar_proxima_senha(self, guiche: Guiche):
        if not guiche.esta_disponivel():
            raise Exception(f"Guichê {guiche.numero} está ocupado.")

        senha = self.senha_service.proxima_senha()
        if senha:
            guiche.atender(senha)
            ultimas_chamadas.appendleft((guiche.numero, senha.numero))
            print(f"Guichê {guiche.numero} chamou senha {senha.numero}")
        else:
            print("Nenhuma senha disponível.")

    def finalizar_atendimento(self, guiche: Guiche):
        if guiche.esta_disponivel():
            print(f"Guichê {guiche.numero} não está atendendo ninguém.")
            return

        senha = guiche.cliente_atual
        self.senha_service.registrar_atendimento(senha)
        guiche.liberar()
        print(f"Guichê {guiche.numero} finalizou atendimento da senha {senha.numero}")
