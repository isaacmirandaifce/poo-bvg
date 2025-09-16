from .usuarioAutenticavel import UsuarioAutenticavel
from .relatorio import Relatorio
from .tipoUsuario import TipoUsuario

class Aluno(UsuarioAutenticavel, Relatorio):
    def __init__(self, nome: str, senha: str):
        super().__init__(nome, senha)
        self.tipo = TipoUsuario.ALUNO
        self.historico = self.HistoricoDisciplinar()

    def autenticar(self, senha: str) -> bool:
        return self._verificar_senha(senha)  # Corrigido!

    def gerar_relatorio(self):
        print(f"Relatório do aluno {self.nome}:")
        for disciplina in self.historico.disciplinas:
            print(f"Disciplina: {disciplina['nome']}, Ano: {disciplina['ano']}, Nota: {disciplina['nota']}")

    # Classe Interna
    class HistoricoDisciplinar:
        def __init__(self):
            self.disciplinas = []

        def adicionar_disciplina(self, nome, ano, nota):
            self.disciplinas.append({
                "nome": nome,
                "ano": ano,
                "nota": nota
            })