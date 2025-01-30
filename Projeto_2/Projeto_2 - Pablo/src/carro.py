class Carro:
    def __init__(self, marca, modelo, ano, cor, placa):
        self.marca = marca
        self.modelo = modelo
        self.ano = ano
        self.cor = cor
        self.__placa = placa  # Atributo privado, protegido de acesso direto

    # Método público para acessar a placa (getter)
    def get_placa(self):
        return self.__placa

    # Método público para modificar a placa (setter)
    def set_placa(self, placa):
        self.__placa = placa

    # Método para exibir as informações do carro (exemplo de uso)
    def exibir_detalhes(self):
        print(f"Marca: {self.marca}")
        print(f"Modelo: {self.modelo}")
        print(f"Ano: {self.ano}")
        print(f"Cor: {self.cor}")
        print(f"Placa: {self.get_placa()}")


