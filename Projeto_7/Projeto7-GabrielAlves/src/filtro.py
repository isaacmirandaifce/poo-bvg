# /Projeto_7/filtro.py

from typing import TypeVar, Generic, List, Callable, Any

# Define um tipo genérico 'T'. Isso permite que a classe Filtro opere
# com qualquer tipo de objeto (Aluno, Professor, etc.).
T = TypeVar('T')

class Filtro(Generic[T]):
    """
    Uma classe genérica que fornece métodos para manipular coleções de objetos
    de qualquer tipo. 
    """
    def __init__(self):
        """Inicializa o filtro com uma lista vazia de elementos."""
        self._elementos: List[T] = []

    def adicionar_elemento(self, elemento: T):
        """
        Adiciona um objeto à coleção do filtro. 
        
        Args:
            elemento (T): O objeto a ser adicionado.
        """
        self._elementos.append(elemento)

    def filtrar_por_condicao(self, condicao: Callable[[T], bool]) -> List[T]:
        """
        Filtra os elementos da coleção com base em uma condição fornecida. 
        A condição é uma função que recebe um elemento e retorna True se ele
        deve ser incluído no resultado.

        Args:
            condicao (Callable[[T], bool]): A função de condição para filtrar.

        Returns:
            List[T]: Uma nova lista contendo os elementos que satisfazem a condição.
        """
        return [item for item in self._elementos if condicao(item)]

    def aplicar_acao_em_todos(self, acao: Callable[[T], None]):
        """
        Aplica uma ação a cada elemento da coleção. 
        A ação é uma função que recebe um elemento mas não retorna valor (ex: print).

        Args:
            acao (Callable[[T], None]): A função/ação a ser aplicada.
        """
        for item in self._elementos:
            acao(item)
    
    def ordenar(self, chave: Callable[[T], Any], reverso: bool = False):
        """
        Implementa um sistema de ordenação genérica. 
        Ordena a lista interna de elementos com base em uma chave de ordenação.

        Args:
            chave (Callable[[T], Any]): Uma função que extrai a chave de comparação
                                        de um elemento (ex: lambda p: p.nome).
            reverso (bool): Se True, ordena em ordem decrescente.
        """
        self._elementos.sort(key=chave, reverse=reverso)