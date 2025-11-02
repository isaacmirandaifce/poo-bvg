from .modelo import Modelo

class Carro:
    
    """Classe Carro com encapsulamento de atributos sensíveis como placa."""
    
    def __init__(self, ano: int, marca: str, modelo: Modelo, cor: str, placa: str):
        self.__ano = ano
        self.__marca = marca
        self.__modelo = modelo
        self.__cor = cor
        self.__placa = placa  

    # getters
    
    def exibir_detalhes(self) -> str:
        
        return (f"Marca: {self.__marca}, Modelo: {self.__modelo}, Ano: {self.__ano}, "
                f"Cor: {self.__cor}, Placa: {self.__placa}")

    def atualizar_cor(self, nova_cor: str):
        self.__cor = nova_cor

    
    # método para acessar placa de forma controlada (ex.: mascarar)
    
    def obter_placa_mascarada(self):
        
        # mostra só os 3 últimos caracteres, por exemplo
        
        return f"***-{self.__placa[-3:]}"