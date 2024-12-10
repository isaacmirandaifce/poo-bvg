from modelo import Modelo

class Carro:
    def __init__(self, ano: int, marca: str, modelo: Modelo, cor: str, placa: str):
        self.__ano = ano
        self.__marca = marca
        self.__modelo = modelo
        self.__cor = cor
        self.__placa = placa

    def exibir_detalhes(self):
        detalhes = (
            f"Detalhes do Carro:\n"
            f"Ano: {self.__ano}\n" 
            f"Marca: {self.__marca}\n"
            f"Modelo: {self.__modelo.get_nome()}\n"
            f"Cor: {self.__cor}\n"
            f"Placa: {self.__placa}"
        )
        return detalhes

    def atualizar_cor(self, nova_cor: str):
        self.__cor = nova_cor
        return f"A cor do carro foi atualizada para {self.__cor}."

    def __repr__(self):
        return (f"Carro(ano={self.__ano}, marca='{self.__marca}', modelo={self.__modelo}, "
                f"cor='{self.__cor}', placa='{self.__placa}')")
