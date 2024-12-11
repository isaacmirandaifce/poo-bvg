# Definição da classe Carro:
class Carro:
    def __init__(self, marca, modelo, ano, cor, placa):
        self.marca = marca
        self.modelo = modelo
        self.ano = ano
        self.cor = cor
        self.__placa = placa

# Método para obter a placa do carro:
    def get_placa(self):
        return self.__placa

# Método para definir uma nova placa, com validação de formato:
    def set_placa(self, placa):
    # Verifica se a placa possui 7 caracteres:
        if len(placa) == 7:
            self.__placa = placa
        else:
            print("Placa inválida!")

# Método para atualizar a cor do carro:
    def atualizar_cor(self, nova_cor):
        self.cor = nova_cor
        print(f"A cor do carro foi atualizada para {self.cor}.")
        
# Método para exibir todos os detalhes do carro:
    def exibir_detalhes(self):
        print(f"Marca: {self.marca}, Modelo: {self.modelo}, Ano: {self.ano}, Cor: {self.cor}, Placa: {self.get_placa()}")

    
    
    
    