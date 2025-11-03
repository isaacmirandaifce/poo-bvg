class Carro:
    def __init__(self, ano, marca, modelo, cor, placa):
        # Inicializa os atributos do carro
        self.ano = ano
        self.marca = marca
        self.modelo = modelo
        self.cor = cor
        self.__placa = placa # encapsulamento da placa do carro

    def exibir_informacoes(self):
        # Exibe as informações do carro, incluindo a placa encapsulada
        print(f"self.marca: {self.marca} {self.modelo} ({self.ano}) - Cor: {self.cor} - Placa: {self.__placa}")

    def atualizar_cor(self, nova_cor):
        # Atualiza a cor do carro
        self.cor = nova_cor
        print(f"A cor do carro foi atualizada para: {nova_cor}")

    def get_placa(self):
        # Método para acessar a placa encapsulada
        return self.__placa
    