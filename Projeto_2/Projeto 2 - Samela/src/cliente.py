from datetime import datetime

class Modelo:
    def __init__(self, nome):
        self.nome = nome

class Carro:
    def __init__(self, ano, marca, modelo, cor, placa):
        self.ano = ano
        self.marca = marca
        self.modelo = modelo
        self.cor = cor
        self.placa = placa

    def exibir_detalhes(self):
        print(f"{self.marca} {self.modelo.nome}, {self.ano}, Cor: {self.cor}, Placa: {self.placa}")

    def atualizar_cor(self, nova_cor):
        self.cor = nova_cor

class Cliente:
    def __init__(self, nome, cpf):
        self.nome = nome
        self.cpf = cpf

    def exibir_informacoes(self):
        print(f"Nome: {self.nome}, CPF: {self.cpf}")

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
        data_final = self.vigencia.split(" a ")[1]
        return datetime.strptime(data_final, "%Y-%m-%d") > datetime.now()
