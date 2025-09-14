# src/professor.py
from .usuario_autenticavel import UsuarioAutenticavel
from .relatorio import Relatorio
from .tipo_usuario import TipoUsuario

class Professor(UsuarioAutenticavel, Relatorio):
    # --- MODIFICAÇÕES DO PROJETO 7 ---
    def __init__(self, nome: str, id_usuario: int, senha: str, departamento: str, disciplinas_ministradas: list = None):
        super().__init__(nome, id_usuario, TipoUsuario.PROFESSOR, senha)
        self._departamento = departamento
        self._disciplinas_ministradas = disciplinas_ministradas if disciplinas_ministradas is not None else []

    @property
    def disciplinas_ministradas(self):
        return self._disciplinas_ministradas

    def __str__(self):
        return f"Professor: {self.nome} (Departamento: {self._departamento})"
    # --- FIM DAS MODIFICAÇÕES ---

    def autenticar(self, senha: str) -> bool:
        return self._senha == senha

    def gerar_relatorio(self) -> None:
        print("--- Relatório do Professor ---")
        print(f"Nome: {self.nome}")
        print(f"ID: {self.id_usuario}")
        print(f"Departamento: {self._departamento}")
        print("Disciplinas Ministradas:")
        if not self._disciplinas_ministradas:
            print("  Nenhuma disciplina associada.")
        else:
            for disciplina in self._disciplinas_ministradas:
                print(f"  - {disciplina}")
        print("-----------------------------\n")