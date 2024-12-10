#importa a classe base Seguro_class
from Seguro_class import Seguro

class carro_seguro(Seguro):
    def __init__(self, cliente, carro, valor_base, vigencia_inicio, vigencia_fim ):

        super().__init__(cliente, valor_base, vigencia_inicio, vigencia_fim)

        self.carro = carro

        def calcular_valor(self):

            if self.carro.ano<2022:
                return self.valores * 1.2
            
            return self.valor_base
        