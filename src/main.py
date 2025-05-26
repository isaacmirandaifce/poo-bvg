# main.py
from carro import Carro
from cliente import Cliente
from seguro import Seguro
from datetime import date

# Criando instâncias de Carro e Cliente
carro1 = Carro(ano=2020, marca="Toyota", modelo="Corolla", cor="Prata", placa="ABC1234")
cliente1 = Cliente(nome="João Silva", cpf="123.456.789-00")

# Exibindo detalhes
carro1.exibir_detalhes()
cliente1.exibir_informacoes()

# Atualizando a cor do carro
carro1.atualizar_cor("Preto")
carro1.exibir_detalhes()

# Criando um seguro
seguro1 = Seguro(carro=carro1, cliente=cliente1, valor=0, vigencia="2025-12-31")

# Calculando valor do seguro e verificando vigência
seguro1.calcular_valor(base_valor=1000, taxa=0.15)
print(f"Valor do seguro: R${seguro1.valor:.2f}")
print("Seguro vigente?", "Sim" if seguro1.verificar_vigencia() else "Não")
