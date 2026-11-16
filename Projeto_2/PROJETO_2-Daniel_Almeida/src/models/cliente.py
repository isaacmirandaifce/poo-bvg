class Cliente:
    """Representa um cliente da seguradora."""

    def __init__(self, nome, cpf):
        """Cria um cliente.

        Args:
            nome (str): Nome completo.
            cpf (str): CPF, armazenado de forma protegida.
        """
        self.nome = nome
        self.__cpf = cpf
        self.__seguros = []

    @property
    def cpf(self):
        """Retorna o CPF mascarado, sem expor o valor completo."""
        return f"***.***.***-{self.__cpf[-2:]}"

    @property
    def seguros(self):
        """Retorna os seguros do cliente (somente leitura)."""
        return tuple(self.__seguros)

    def adicionar_seguro(self, seguro):
        """Associa um seguro a este cliente."""
        self.__seguros.append(seguro)