# src/aluno.py
from .usuario_autenticavel import UsuarioAutenticavel
from .relatorio import Relatorio
from .tipo_usuario import TipoUsuario
from typing import List

class Aluno(UsuarioAutenticavel, Relatorio):
    class HistoricoDisciplinar:
        def __init__(self, nome_disciplina: str, ano_cursado: int, nota: float):
            self.nome_disciplina = nome_disciplina
            self.ano_cursado = ano_cursado
            self.nota = nota
        def __str__(self) -> str:
            return f"  - Disciplina: {self.nome_disciplina}, Ano: {self.ano_cursado}, Nota: {self.nota}"

    def __init__(self, nome: str, id_usuario: int, senha: str, curso: str):
        super().__init__(nome, id_usuario, TipoUsuario.ALUNO, senha)
        self._curso = curso
        self._historico: List[Aluno.HistoricoDisciplinar] = []

    # --- ADIÇÕES DO PROJETO 7 ---
    @property
    def historico(self):
        return self._historico

    def calcular_media(self) -> float:
        if not self._historico:
            return 0.0
        notas = [disciplina.nota for disciplina in self._historico]
        return sum(notas) / len(notas)

    def __str__(self) -> str:
        return f"Aluno: {self.nome} | Média: {self.calcular_media():.2f}"
    # --- FIM DAS ADIÇÕES ---

    def adicionar_disciplina_historico(self, nome_disciplina: str, ano_cursado: int, nota: float):
        nova_disciplina = self.HistoricoDisciplinar(nome_disciplina, ano_cursado, nota)
        self._historico.append(nova_disciplina)

    def autenticar(self, senha: str) -> bool:
        return self._senha == senha

    def gerar_relatorio(self) -> None:
        print("--- Relatório do Aluno ---")
        print(f"Nome: {self.nome}")
        print(f"ID: {self.id_usuario}")
        print(f"Curso: {self._curso}")
        print(f"Média Geral: {self.calcular_media():.2f}")
        print("Histórico de Disciplinas:")
        if not self._historico:
            print("  Nenhuma disciplina cursada.")
        else:
            for disciplina in self._historico:
                print(disciplina)
        print("--------------------------\n")