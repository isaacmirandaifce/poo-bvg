from models.senhas import Senha
from utils.factory import criar_cliente
from services.senha_service import SenhaService

senha_service = SenhaService()

def emitir_senha(nome, cpf, tipo):
    cliente = criar_cliente(nome, cpf, tipo)
    senha = senha_service.emitir_senha(cliente)
    return senha
