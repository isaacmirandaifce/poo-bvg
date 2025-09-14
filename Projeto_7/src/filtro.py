# src/filtro.py
from typing import List, Callable, TypeVar, Generic

T = TypeVar('T') # Define um tipo genérico T

class Filtro(Generic[T]):
    """
    Uma classe genérica para armazenar, filtrar, ordenar e manipular uma coleção de elementos.
    """
    def __init__(self):
        self.elementos: List[T] = []

    def adicionar_elemento(self, elemento: T):
        self.elementos.append(elemento)

    def filtrar_por_condicao(self, condicao: Callable[[T], bool]) -> List[T]:
        return [elem for elem in self.elementos if condicao(elem)]

    def aplicar_acao(self, acao: Callable[[T], None]):
        for elemento in self.elementos:
            acao(elemento)
            
    # --- MÉTODO QUE ESTAVA FALTANDO ---
    def ordenar(self, chave: Callable[[T], any], reverso: bool = False):
        """
        Ordena os elementos da coleção interna com base em uma chave.
        """
        self.elementos.sort(key=chave, reverse=reverso)
