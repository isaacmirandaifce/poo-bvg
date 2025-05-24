class Modelo:
    def __init__(self, nome):
        self._nome = nome

    def nome(self):
        return self._nome

    def __str__(self):
        return self._nome


class Carro:
    def __init__(self, ano, marca, modelo: Modelo, cor, placa):
        self._ano = ano
        self._marca = marca
        self._modelo = modelo
        self._cor = cor
        self._placa = placa

    def ano(self):
        return self._ano

    def marca(self):
        return self._marca

    def modelo(self):
        return self._modelo

    def cor(self):
        return self._cor

    def placa(self):
        return self._placa

    def __str__(self):
        return f"{self.marca()} {self.modelo()} ({self.ano()}) - {self.cor()} - Placa: {self.placa()}"


class Cliente:
    def __init__(self, nome, cpf):
        self._nome = nome
        self._cpf = cpf

    def nome(self):
        return self._nome

    def cpf(self):
        return self._cpf

    def __str__(self):
        return f"{self.nome()} - CPF: {self.cpf()}"


class Seguro:
    def __init__(self, carro: Carro, cliente: Cliente, valor, vigencia):
        self._carro = carro
        self._cliente = cliente
        self._valor = valor
        self._vigencia = vigencia

    def carro(self):
        return self._carro

    def cliente(self):
        return self._cliente

    def valor(self):
        return self._valor

    def vigencia(self):
        return self._vigencia

    def __str__(self):
        return (f"Seguro de {self.carro()}\n"
                f"Cliente: {self.cliente()}\n"
                f"Valor: R${self.valor():.2f} - Vigência: {self.vigencia()}")

