from typing import TypeVar, Generic, List, Callable
T = TypeVar('T')

class DataFilter(Generic[T]):
    def __init__(self):
        self.__dados: List[T] = []

    def adicionar(self, elemento: T) -> None:
        self.__dados.append(elemento)

    def filtrar(self, condicao: Callable[[T], bool]) -> List[T]:
        """Recebe uma lambda e retorna uma lista filtrada."""
        return [elemento for elemento in self.__dados if condicao(elemento)]

    def processar(self, acao: Callable[[T], None]) -> None:
        """Recebe uma lambda e executa uma ação para cada elemento."""
        for elemento in self.__dados:
            acao(elemento)