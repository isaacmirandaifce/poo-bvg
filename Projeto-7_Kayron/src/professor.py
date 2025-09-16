from .usuarioAutenticavel import UsuarioAutenticavel
from .relatorio import Relatorio
from .tipoUsuario import TipoUsuario


class Professor(UsuarioAutenticavel, Relatorio):
    def __init__(self, nome: str, senha: str, disciplina: str):
        super().__init__(nome, senha)
        self.tipo = TipoUsuario.PROFESSOR
        self.disciplina = disciplina

    def autenticar(self, senha: str) -> bool:
        return self._verificar_senha(senha)

    def gerar_relatorio(self):
        print(f"Relatório do Professor {self.nome}:")
        print(f"Disciplina lecionada: {self.disciplina}")
