import os
from models.senhas import Senha
from dados.fila_data import fila_prioritaria, fila_normal
from dao.senha_dao import SenhaDAO

class SenhaService:
    def __init__(self):
        self.dao = SenhaDAO()

    def emitir_senha(self, cliente):
        senha = Senha(cliente, cliente.tipo)

        # Salvar no JSON utilizando a camada DAO com tratamento de exceções
        try:
            dados = self.dao.carregar_dados()
            dados['emitidas'].append(senha.to_dict())
            self.dao.salvar_dados(dados)
        except Exception as e:
            raise Exception(f"Erro ao emitir senha: {e}")

        # Adicionar à fila correta
        if senha.tipo == 'P':
            fila_prioritaria.append(senha)
        else:
            fila_normal.append(senha)

        return senha

    def proxima_senha(self):
        if fila_prioritaria:
            return fila_prioritaria.popleft()
        elif fila_normal:
            return fila_normal.popleft()
        return None

    def registrar_atendimento(self, senha):
        try:
            dados = self.dao.carregar_dados()
            senha.status = 'finalizado'
            dados['emitidas'] = [s for s in dados['emitidas'] if s['numero'] != senha.numero]
            dados['atendidas'].append(senha.to_dict())
            self.dao.salvar_dados(dados)
        except Exception as e:
            raise Exception(f"Erro ao registrar atendimento: {e}")
