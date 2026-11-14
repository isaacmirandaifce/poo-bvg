"""Entidade Cliente"""

class Cliente:
    """Representa um cliente (titular) que pode possuir vários seguros.

    O CPF é um dado sensível e por isso é mantido em um atributo privado
    (``__cpf``). Fora da classe ele só é exposto de forma mascarada.

    Attributes:
        nome (str): Nome completo do cliente."""

    def __init__(self, nome, cpf):
        """Cria um cliente sem seguros.

        Args:
            nome (str): Nome completo do cliente.
            cpf (str): CPF do cliente (ex.: ``"123.456.789-00"``).

        Raises:
            ValueError: Se o nome ou o CPF forem vazios."""
        if not nome or not nome.strip():
            raise ValueError("O nome do cliente é obrigatório.")
        if not cpf or not cpf.strip():
            raise ValueError("O CPF do cliente é obrigatório.")
        self.nome = nome
        self.__cpf = cpf 
        self.__seguros = [] 

    @property
    def cpf_mascarado(self):
        """str: CPF com os dígitos ocultos (ex.: ``***.456.***-**``)."""
        digitos = "".join(c for c in self.__cpf if c.isdigit())
        if len(digitos) != 11:
            return "***"
        return f"***.{digitos[3:6]}.***-**"

    @property
    def seguros(self):
        """tuple: Seguros do cliente (somente leitura, em forma de tupla)."""
        return tuple(self.__seguros)

    def adicionar_seguro(self, seguro):
        """Associa um seguro ao cliente.

        Args:
            seguro (Seguro): Qualquer objeto da hierarquia ``Seguro``."""
        if seguro not in self.__seguros:
            self.__seguros.append(seguro)

    def calcular_total_premios(self):
        """Soma o prêmio de todos os seguros do cliente.

        O cliente não sabe qual é o tipo de cada seguro: apenas chama
        ``calcular_premio()`` (polimorfismo).

        Returns:
            float: Soma dos prêmios de todos os seguros associados."""
        return sum(seguro.calcular_premio() for seguro in self.__seguros)

    def exibir_informacoes(self):
        """Retorna os dados do cliente com o CPF mascarado.

        Returns:
            str: Texto com nome e CPF mascarado."""
        return f"Nome: {self.nome}, CPF: {self.cpf_mascarado}"

    def __str__(self):
        return self.exibir_informacoes()
