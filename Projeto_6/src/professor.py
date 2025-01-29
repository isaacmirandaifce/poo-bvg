from usuario_autenticavel import UsuarioAutenticavel
from relatorio import Relatorio

class Professor(UsuarioAutenticavel, Relatorio):
    def __init__(self, nome, senha):
        super().__init__(nome, senha)

    def autenticar(self, senha: str) -> bool:
        return self.get_senha() == senha

    def gerar_relatorio(self):
        return f"Relatório do Professor {self.get_nome()}: Detalhes do desempenho acadêmico."
