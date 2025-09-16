from usuario import Usuario
from typing import List

class Aluno(Usuario):
    def __init__(self, nome: str, id_usuario: int, curso: str, notas: List[float]):
        super().__init__(nome, id_usuario)
        self.curso = curso
        self.notas = notas
    
    def media(self) -> float:
        return sum(self.notas) / len(self.notas) if self.notas else 0.0
