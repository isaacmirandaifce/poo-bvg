# Teste com instâncias reais do sistema de seguros

from classes import Cliente, Carro, Seguro

# Criando um cliente
cliente1 = Cliente("João Silva", "123.456.789-00")

# Criando um carro
carro1 = Carro(2020, "Toyota", "Corolla", "Branco", "XYZ-1234")

# Criando um seguro
seguro1 = Seguro(carro1, cliente1, 1500.00, "01/01/2024", "01/01/2025")

# Exibindo as informações
cliente1.exibir_informacoes()
carro1.exibir_detalhes()
print(f"Valor do seguro: R$ {seguro1.valor}")
print("Seguro válido em 01/06/2024?", seguro1.verificar_vigencia("01/06/2024"))
print("Seguro válido em 01/01/2026?", seguro1.verificar_vigencia("01/01/2026"))
