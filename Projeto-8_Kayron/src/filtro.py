from typing import TypeVar, Generic, List, Callable, Any

T = TypeVar('T')

class Filtro(Generic[T]):
    def __init__(self):
        self.elementos: List[T] = []

    def adicionar_elemento(self, elemento: T):
        self.elementos.append(elemento)

    def filtrar_por_condicao(self, condicao: Callable[[T], bool]) -> List[T]:
        return [el for el in self.elementos if condicao(el)]

    def imprimir_todos(self, acao: Callable[[T], None]):
        for el in self.elementos:
            acao(el)

    def ordenar(self, chave: Callable[[T], Any], reverso: bool = False) -> List[T]:
        return sorted(self.elementos, key=chave, reverse=reverso)
