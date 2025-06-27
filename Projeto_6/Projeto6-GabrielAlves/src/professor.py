from typing import List
from usuario import UsuarioAutenticavel
from interfaces import Relatorio
from enums import TipoUsuario

class Professor(UsuarioAutenticavel, Relatorio):
    """
    Representa um professor, que pode se autenticar e gerar relatórios
    sobre as disciplinas que leciona. 
    """
    TIPO = TipoUsuario.PROFESSOR

    def __init__(self, nome: str, id_usuario: int, senha: str, departamento: str):
        super().__init__(nome, id_usuario, senha)
        self._departamento = departamento
        self._disciplinas_lecionadas: List[str] = []

    def adicionar_disciplina(self, nome_disciplina: str):
        """Adiciona uma disciplina à lista do professor."""
        self._disciplinas_lecionadas.append(nome_disciplina)

    def gerar_relatorio(self) -> None: # Implementação da interface Relatorio [cite: 12]
        """
        Gera um relatório com os detalhes do professor e as disciplinas que leciona. [cite: 12]
        """
        print("--- Relatório do Professor ---")
        print(f"Nome: {self.nome}")
        print(f"ID: {self._id_usuario}")
        print(f"Departamento: {self._departamento}")
        print("Disciplinas Lecionadas:")
        if not self._disciplinas_lecionadas:
            print("  Nenhuma disciplina atribuída.")
        else:
            for disciplina in self._disciplinas_lecionadas:
                print(f"  - {disciplina}")
        print("-" * 30)