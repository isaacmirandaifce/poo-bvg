from datetime import datetime, timedelta
from seguro import Carro, Cliente, Seguro 

c1 = Cliente('João', 12345678910)
print(c1.exibir_informacoes())

carro1 = Carro(2021, 'Corolla', 'Toyota', 'Branco', 'HXY-1B43')
print(carro1.exibir_detalhes())

carro1.atualizar_cor('Vermelho')
print('Cor atualizada:', carro1.exibir_detalhes()) 

vigencia = datetime.now().date() + timedelta(days=365)
seguro1 = Seguro(carro1, c1, 0, vigencia)


base_valor = int(input("Valor base: "))

taxa = 0.1
valor_total = seguro1.calcular_valor(base_valor, taxa)

print (f"Valor do seguro: R$ {valor_total: .2f}") 

validade = seguro1.verificar_vigencia()
print(f"Vigencia do seguro: {validade}")
