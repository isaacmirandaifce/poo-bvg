from datetime import datetime
from carro import Carro 
from cliente import Cliente  

class Seguro:
    def __init__(self, carro: Carro, cliente: Cliente, valor: float, vigencia: str):
        self.__carro = carro
        self.__cliente = cliente  
        self.__valor = valor  
        self.__vigencia = vigencia  #(formato DD-MM-YYYY)

    def calcular_valor(self, base_valor: float, taxa: float) -> float:
        valor_final = base_valor + (base_valor * taxa)
        return valor_final

    def verificar_vigencia(self) -> bool:
        data_atual = datetime.now().date()
        data_vigencia = datetime.strptime(self.__vigencia, "%d-%m-%Y").date()
        return data_atual <= data_vigencia

    def exibir_detalhes(self):
        return {
            "cliente": self.__cliente.exibir_informacoes(),
            "carro": self.__carro.exibir_detalhes(),
            "valor_seguro": self.__valor,
            "vigencia": self.__vigencia
        }
