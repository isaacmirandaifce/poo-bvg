from usuario_autenticavel import UsuarioAutenticavel
from relatorio import Relatorio
from tipo_usuario import TipoUsuario

class Aluno(UsuarioAutenticavel, Relatorio):
    def __init__(self, nome, login, senha):
        super().__init__(nome, login, senha, TipoUsuario.ALUNO)
        self.historico = []

    class HistoricoDisciplinar:
        def __init__(self, nome_disciplina, ano, nota):
            self.nome_disciplina = nome_disciplina
            self.ano = ano
            self.nota = nota

    def adicionar_disciplina(self, nome_disciplina, ano, nota):
        self.historico.append(self.HistoricoDisciplinar(nome_disciplina, ano, nota))

    def autenticar(self, senha: str) -> bool:
        return self._verificar_senha(senha)

    def gerar_relatorio(self):
        print(f"\nRelatório do Aluno: {self.nome}")
        for d in self.historico:
            print(f"Disciplina: {d.nome_disciplina} | Ano: {d.ano} | Nota: {d.nota}")
