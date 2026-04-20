"""
    Decidi criar essa classe e suas subclasses pois notei que averia muita repetição dos atributos ano, marca, modelo, etc...
    então decidi juntar tudo em uma classe pai onde outras classes herdariam esses atributos e assim diminuiria a repetição
"""

"""
    Fazemos a criação da classe pai "Veiculo" onde nela armazenamos os atributos mais genéricos.
    definimos o atributo "placa" como private, como a atividade pede.

    Também definimos o metodo "trocar_cor" onde o usuário pode trocar a cor do veículo
"""
class Veiculo:
    def __init__ (self, ano, marca, modelo, cor, placa):
        self.ano = ano
        self.marca = marca
        self.modelo = modelo
        self.cor = cor
        self.__placa = placa

    @property
    def get_placa(self):
        return self.__placa
    
    def trocar_cor(self, cor_nova):
        print(f"Cor do carro trocada de {self.cor} para {cor_nova}!")
        self.cor = cor_nova

"""
    Classe "Carro" e "Moto" ambas herdam da classe pai (Veiculo)
    Possuem um metodo chamado exibir detalhes, onde imprimem os detalhes do veículo.
"""
class Carro(Veiculo):
    def __init__(self, ano, marca, modelo, cor, placa, portas=4):
        super().__init__(ano, marca, modelo, cor, placa)
        self.portas = portas

    def exibir_detalhes(self):
        print(f"Carro {self.portas} portas\nAno: {self.ano}\nMarca: {self.marca}\nModelo: {self.modelo}\nCor: {self.cor}\nPlaca: {self.get_placa}")

class Moto(Veiculo):
    def __init__(self, ano, marca, modelo, cor, placa, cilindradas=12):
        super().__init__(ano, marca, modelo, cor, placa)
        self.cilindradas = cilindradas
    
    def exibir_detalhes(self):
        print(f"Moto {self.cilindradas} cilindradas\nAno: {self.ano}\nMarca: {self.marca}\nModelo: {self.modelo}\nCor: {self.cor}\nPlaca: {self.get_placa}")