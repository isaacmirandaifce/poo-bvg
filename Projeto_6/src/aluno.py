from usuario_autenticavel import UsuarioAutenticavel
from relatorio import Relatorio
from tipo_usuario import TipoUsuario

class Aluno(UsuarioAutenticavel, Relatorio):
    def __init__(self, nome, email, senha):
        super().__init__(nome, email)
        self._senha = senha
        self._historico = self.HistoricoDisciplinar()

    def autenticar(self, senha: str) -> bool:
        return self._senha == senha

    def gerar_relatorio(self) -> str:
        return f"Relatório do Aluno: {self.nome}\n{self._historico}"

    class HistoricoDisciplinar:
        def __init__(self):
            self.disciplinas = []

        def adicionar_disciplina(self, nome_disciplina, ano, nota):
            self.disciplinas.append({
                "nome": nome_disciplina,
                "ano": ano,
                "nota": nota
            })

        def __str__(self):
            return "\n".join([f"Disciplina: {d['nome']}, Ano: {d['ano']}, Nota: {d['nota']}" for d in self.disciplinas])