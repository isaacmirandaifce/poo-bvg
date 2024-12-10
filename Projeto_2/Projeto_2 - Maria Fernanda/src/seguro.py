from dataclasses import dataclass
from datetime import datetime
from carro import Carro
from cliente import Cliente 

# Criação da Classe Seguro
@dataclass
class Seguro:
    carro: Carro
    cliente: Cliente
    valor: float
    vigencia: str 

# Método para calcular o valor do seguro
    def calcular_valor(self, base_valor, taxa):
        self.valor = base_valor * (1 + taxa)
        print(f"Valor do seguro calculado: R$ {self.valor:.2f}")

# Método para verificar a vigência do seguro
    def verificar_vigencia(self):
        data_vigencia = datetime.strptime(self.vigencia, "%Y-%m-%d").date()
        hoje = datetime.now().date()
        return hoje <= data_vigencia

# Método para exibir as informações do seguro
    def exibir_informacao(self):
        print("=== Informações do Seguro ===")
        self.carro.exibir_detalhes()
        self.cliente.exibir_informacoes()
        print(f"Valor do Seguro: R$ {self.valor:.2f}")
        print(f"Vigência: {self.vigencia}")
        if self.verificar_vigencia():
            print("O seguro está válido.")
        else:
            print("O seguro está expirado.")