import sys
import os

# Avisa para o python onde localizar o arquivo:
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'src')))

# Classes importadas:
from Classe_Cliente import Cliente
from Classe_Carro import Carro
from Classe_SeguroCarro import Seguro


class Seguro:
    def __init__(self, cliente, carros, valor, vigencia_inicio, vigencia_fim):
        self.cliente = cliente
        self.carros = carros
        self.valor = valor
        self.vigencia_inicio = vigencia_inicio  # agora é uma string no formato 'YYYY-MM-DD'
        self.vigencia_fim = vigencia_fim  # mesma coisa aqui

    def calcular_valor(self, base_valor, taxa):
        self.valor = base_valor * (1 + taxa) * len(self.carros)
        return self.valor

    def verificar_vigencia(self):
        data_atual = "2024-12-10"  # Exemplo de data atual em formato de string
        if self.vigencia_inicio <= data_atual <= self.vigencia_fim:
            return "A apólice está válida."
        return "A apólice está expirada."


if __name__ == "__main__":
    # Criação de cliente
    cliente = Cliente("Taíssa Moreira", "123.456.789-00")

    # Criação de veículos
    carro1 = Carro("Toyota", "Corolla", 2020, "Branco", "XYZ-1234")
    carro2 = Carro("Honda", "Civic", 2022, "Preto", "DEF-5678")

    # Criação de seguros
    seguro_carro = Seguro(cliente, [carro1, carro2], 0, "2024-01-01", "2025-01-01")
    seguro_carro.calcular_valor(1000, 0.05)

    # Adicionar seguro ao cliente
    cliente.adicionar_seguro(seguro_carro)

    # Exibir informações
    cliente.exibir_informacoes()

    # Verificar vigência
    print(seguro_carro.verificar_vigencia())


#        FUNÇÃO verificar_vigencia: 
#            DATA_ATUAL ← OBTER_DATA_ATUAL()  
    
#            SE VIGENCIA_INICIO <= DATA_ATUAL <= VIGENCIA_FIM ENTÃO
#                RETORNAR "O seguro está válido."
#            SENÃO
#                RETORNAR "O seguro está expirado."
#            FIM SE
#        FIM FUNÇÃO
