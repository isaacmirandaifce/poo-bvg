"""Módulo contendo a entidade Cliente."""

class Cliente:
    """Classe que representa um cliente da seguradora InsureTech Pro."""
    
    def __init__(self, nome: str, cpf: str):
        """
        Inicializa um novo Cliente.
        
        Args:
            nome (str): Nome completo do cliente.
            cpf (str): CPF do cliente (dado sensível).
        """
        self._nome = nome
        self.__cpf = cpf  # Atributo privado para proteger dado sensível
        
    @property
    def nome(self) -> str:
        """Retorna o nome do cliente."""
        return self._nome
        
    @property
    def cpf(self) -> str:
        """Retorna o CPF do cliente."""
        return self.__cpf