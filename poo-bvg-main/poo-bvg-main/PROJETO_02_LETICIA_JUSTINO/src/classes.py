# Definição das classes para o sistema de seguros de veículos

class Carro:
    def __init__(self, ano, marca, modelo, cor, placa):
        # Atributos do carro
        self.__ano = ano
        self.__marca = marca
        self.__modelo = modelo
        self.__cor = cor
        self.__placa = placa

    def exibir_detalhes(self):
        # Exibe os detalhes do carro
        print(f"Ano: {self.__ano}, Marca: {self.__marca}, Modelo: {self.__modelo}, Cor: {self.__cor}, Placa: {self.__placa}")

    def atualizar_cor(self, nova_cor):
        # Atualiza a cor do carro
        self.__cor = nova_cor

    def get_placa(self):
        # Retorna a placa do carro
        return self.__placa


class Cliente:
    def __init__(self, nome, cpf):
        # Atributos do cliente
        self.__nome = nome
        self.__cpf = cpf

    def exibir_informacoes(self):
        # Exibe as informações do cliente
        print(f"Nome: {self.__nome}, CPF: {self.__cpf}")

    def get_cpf(self):
        # Retorna o CPF do cliente
        return self.__cpf


class Seguro:
    def __init__(self, carro, cliente, valor, data_inicio, data_fim):
        # Atributos do seguro
        self.carro = carro
        self.cliente = cliente
        self.valor = valor
        self.data_inicio = data_inicio  # formato 'dd/mm/aaaa'
        self.data_fim = data_fim        # formato 'dd/mm/aaaa'

    def calcular_valor(self, base_valor, taxa):
        # Calcula o valor do seguro com base no valor base e taxa
        self.valor = base_valor + (base_valor * taxa)
        return self.valor

    def verificar_vigencia(self, data_atual):
        # Verifica se a data atual está dentro da vigência
        return self.data_inicio <= data_atual <= self.data_fim


# Herança para outros tipos de seguros

class SeguroVeiculo:
    def __init__(self, cliente, valor, data_inicio, data_fim):
        # Classe base para seguros de veículos
        self.cliente = cliente
        self.valor = valor
        self.data_inicio = data_inicio
        self.data_fim = data_fim

    def calcular_valor(self, base_valor, taxa):
        # Método genérico para calcular valor
        self.valor = base_valor + (base_valor * taxa)
        return self.valor


class SeguroCarro(SeguroVeiculo):
    def __init__(self, cliente, valor, data_inicio, data_fim, carro):
        # Herda de SeguroVeiculo e adiciona o carro
        super().__init__(cliente, valor, data_inicio, data_fim)
        self.carro = carro

    def calcular_valor(self, base_valor, taxa):
        # Cálculo específico para seguro de carro
        self.valor = (base_valor + (base_valor * taxa)) * 1.1
        return self.valor


class SeguroMoto(SeguroVeiculo):
    def __init__(self, cliente, valor, data_inicio, data_fim, cilindradas):
        # Herda de SeguroVeiculo e adiciona cilindradas da moto
        super().__init__(cliente, valor, data_inicio, data_fim)
        self.cilindradas = cilindradas

    def calcular_valor(self, base_valor, taxa):
        # Cálculo específico para seguro de moto
        fator = 1.2 if self.cilindradas > 300 else 1.0
        self.valor = (base_valor + (base_valor * taxa)) * fator
        return self.valor
