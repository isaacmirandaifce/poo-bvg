from typing import TypeVar, Generic, List, Callable

T = TypeVar("T")  # Define um tipo genérico

class Filtro(Generic[T]):
    def __init__(self):
        self.elementos: List[T] = []  # Lista genérica

    def adicionar_elemento(self, elemento: T):
        """ Adiciona um elemento genérico à lista """
        self.elementos.append(elemento)

    def filtrar_por_condicao(self, condicao: Callable[[T], bool]) -> List[T]:
        """ Filtra elementos com base em uma condição """
        return [el for el in self.elementos if condicao(el)]

    def ordenar_por_atributo(self, atributo: str, reverso=False):
        """ Ordena a lista pelo atributo especificado """
        self.elementos.sort(key=lambda x: getattr(x, atributo), reverse=reverso)

    def imprimir_todos(self, acao: Callable[[T], None]):
        """ Aplica uma ação (como print) a todos os elementos """
        for el in self.elementos:
            acao(el)
