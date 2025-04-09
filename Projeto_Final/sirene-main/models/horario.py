from enum import Enum

class StatusAlarme(Enum):
    PENDENTE = "Pendente"
    SUCESSO = "Sucesso"
    ERRO = "Erro"
    NAO_OCORREU = "Não Ocorrido"

class Horario:
    def __init__(self, id, horario, status=StatusAlarme.PENDENTE):
        self.id = id
        self.horario = horario
        self.status = status

    def atualizar_status(self, novo_status):
        self.status = novo_status
