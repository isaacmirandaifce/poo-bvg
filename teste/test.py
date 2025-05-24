from modelo.cliente import Cliente
from modelo.carro import Carro
from seguradora.seguro import Seguro
from datetime import datetime

carro1= Carro(2020, "Toyota", "Corolla", "Branco", "XYZ-1234")
cliente1= Cliente("João Silva", "123.456.789-00")
seguro1= Seguro(carro1, cliente1, 1500.00, "01/01/2024", "01/01/2025")

cliente1.exibir_informacoes()
carro1.exibir_detalhes()
carro1.atualizar_cor("vermelho")
seguro1.calcular_valor(0.04)
seguro1.verificar_vigencia()