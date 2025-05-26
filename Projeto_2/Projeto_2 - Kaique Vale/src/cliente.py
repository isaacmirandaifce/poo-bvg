class Modelo:
    def __init__(self, nome):
        self.nome = nome

class Carro:
    def __init__(self, ano, marca, modelo, cor, placa):
        self.ano = ano
        self.marca = marca
        self.modelo = modelo
        self.cor = cor
        self.__placa = placa

    def get_placa(self):
        return self.__placa

    def exibir_detalhes(self):
        print(f"{self.ano} {self.marca} {self.modelo.nome} - {self.cor} - Placa: {self.__placa}")

    def atualizar_cor(self, nova_cor):
        self.cor = nova_cor

class Cliente:
    def __init__(self, nome, cpf):
        self.nome = nome
        self.__cpf = cpf

    def get_cpf(self):
        return self.__cpf

    def exibir_informacoes(self):
        print(f"Nome: {self.nome} | CPF: {self.__cpf}")

class Seguro:
    def __init__(self, carro, cliente, valor, vigencia):
        self.carro = carro
        self.cliente = cliente
        self.valor = valor
        self.vigencia = vigencia

    def calcular_valor(self, base_valor, taxa):
        self.valor = base_valor * (1 + taxa)
        return self.valor

    def verificar_vigencia(self):
        return self.vigencia == "ativa"
