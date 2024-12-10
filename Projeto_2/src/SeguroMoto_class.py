from Seguro_class import Seguro

class moto_seguro(Seguro):
     def __init__(self, cliente, moto, valor_base, vigencia_inicio, vigencia_fim):

        super().__init__(cliente, valor_base, vigencia_inicio, vigencia_fim)

        self.moto = moto

        def calcular_Valor(self):
            
            if self.moto.ano<2022:
                return self.valor_base * 1.5
            
            return self.valor_base