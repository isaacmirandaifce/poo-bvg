class Usuario:
    def __init__(self, nome='', email='', tipo=''):
        """
        Construtor padrão e parametrizado.
        """
        self._nome = nome
        self._email = email
        self._tipo = tipo

    def gerar_relatorio(self):
        """
        Método abstrato para gerar relatório.
        Deve ser implementado por classes derivadas.
        """
        raise NotImplementedError("O método 'gerar_relatorio' deve ser implementado na subclasse.")

    # Métodos acessores
    @property
    def nome(self):
        return self._nome

    @property
    def email(self):
        return self._email

    @property
    def tipo(self):
        return self._tipo
