from typing import TypeVar, Generic, List, Callable

T = TypeVar('T')  # Definição do tipo genérico

class Filtro(Generic[T]):
    def __init__(self):
        self._elementos: List[T] = []

    def adicionarElemento(self, elemento: T):
        """Adiciona um objeto ao filtro."""
        self._elementos.append(elemento)

    def filtrarPorCondicao(self, condicao: Callable[[T], bool]) -> List[T]:
        """Filtra os elementos com base em uma condição."""
        return [elem for elem in self._elementos if condicao(elem)]

    def imprimirTodos(self, acao: Callable[[T], None]):
        """Aplica uma ação a cada elemento (como imprimir informações no console)."""
        for elem in self._elementos:
            acao(elem)

    def ordenar(self, chave: Callable[[T], any], reverso: bool = False):
        """Ordena a lista de elementos com base em um critério específico."""
        self._elementos.sort(key=chave, reverse=reverso)