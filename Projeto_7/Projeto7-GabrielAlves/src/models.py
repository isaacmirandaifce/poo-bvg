# /Projeto_7/models.py

from dataclasses import dataclass, field
from typing import List

@dataclass
class Disciplina:
    """Representa uma disciplina no sistema acadêmico."""
    nome: str
    codigo: str

@dataclass
class Matricula:
    """Representa a matrícula de um aluno em uma disciplina em um ano específico."""
    disciplina: Disciplina
    ano: int
    nota_final: float

@dataclass
class Aluno:
    """Representa um aluno no sistema acadêmico."""
    nome: str
    matricula_id: str
    historico: List[Matricula] = field(default_factory=list)

    def calcular_media_geral(self) -> float:
        """Calcula a média geral do aluno com base em seu histórico."""
        if not self.historico:
            return 0.0
        total_notas = sum(m.nota_final for m in self.historico)
        return total_notas / len(self.historico)

@dataclass
class Professor:
    """Representa um professor no sistema acadêmico."""
    nome: str
    departamento: str
    disciplinas_lecionadas: List[Disciplina] = field(default_factory=list)