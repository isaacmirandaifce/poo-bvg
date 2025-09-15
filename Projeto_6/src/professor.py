from usuario_autenticavel import UsuarioAutenticavel
from relatorio import Relatorio
from tipo_usuario import TipoUsuario

class Professor(UsuarioAutenticavel, Relatorio):
    def __init__(self, nome, login, senha, disciplina):
        super().__init__(nome, login, senha, TipoUsuario.PROFESSOR)
        self.disciplina = disciplina

    def autenticar(self, senha: str) -> bool:
        return self._verificar_senha(senha)

    def gerar_relatorio(self):
        print(f"\nRelatório do Professor: {self.nome}")
        print(f"Disciplina: {self.disciplina}")
