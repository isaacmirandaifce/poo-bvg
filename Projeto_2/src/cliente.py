class Cliente:
    def __init__(self, nome, cpf):
        self._nome = nome
        self._cpf = cpf

    def get_nome(self):
        return self._nome

    def get_cpf(self):
        return self._cpf

    def exibir_informacoes(self):
        return f"{self._nome} - CPF: {self._cpf}"

    def __str__(self):
        return self.exibir_informacoes()
