from carro import Carro
from cliente import Cliente
from seguro import Seguro

cliente1 = Cliente("João Silva", "123.456.789-00")
carro1 = Carro(2020, "Toyota", "Corolla", "Branco", "XYZ-1234")
seguro1 = Seguro(carro1, cliente1, 1500, "01/01/2024 a 01/01/2025")

cliente1.exibir_informacoes()
carro1.exibir_detalhes()
print(seguro1.verificar_vigencia())
