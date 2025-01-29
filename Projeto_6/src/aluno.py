from usuario_autenticavel import UsuarioAutenticavel
from relatorio import Relatorio

class Aluno(UsuarioAutenticavel, Relatorio):
    class HistoricoDisciplinar:
        def __init__(self):
            self.disciplinas = []

        def adicionar_disciplina(self, nome, ano, nota):
            self.disciplinas.append({
                'nome': nome,
                'ano': ano,
                'nota': nota
            })

        def obter_historico(self):
            return self.disciplinas

    def __init__(self, nome, senha):
        super().__init__(nome, senha)
        self.historico = self.HistoricoDisciplinar()

    def autenticar(self, senha: str) -> bool:
        return self.get_senha() == senha

    def gerar_relatorio(self):
        historico = self.historico.obter_historico()
        relatorio = f"Relatório do Aluno {self.get_nome()}:\n"
        for disciplina in historico:
            relatorio += f"Disciplina: {disciplina['nome']}, Ano: {disciplina['ano']}, Nota: {disciplina['nota']}\n"
        return relatorio
