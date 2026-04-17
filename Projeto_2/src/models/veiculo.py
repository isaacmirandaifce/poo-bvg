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