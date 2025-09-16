from typing import List, TypeVar, Callable

T = TypeVar('T')

class Filtro:
    def __init__(self):
        self.elementos: List[T] = []

    def adicionar_elemento(self, elemento: T) -> None:
        """Adiciona um objeto ao filtro."""
        self.elementos.append(elemento)

    def filtrar_por_condicao(self, condicao: Callable[[T], bool]) -> List[T]:
        """Filtra os elementos com base em uma condição."""
        return list(filter(condicao, self.elementos))

    def imprimir_todos(self, acao: Callable[[T], None]) -> None:
        """Aplica uma ação a cada elemento, como imprimir informações."""
        for elemento in self.elementos:
            acao(elemento)
