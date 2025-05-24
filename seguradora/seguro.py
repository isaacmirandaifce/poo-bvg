from datetime import datetime

class Seguro:
    def __init__(self, carro, cliente, valor, data_inicio, data_fim):
        self.carro = carro
        self.cliente = cliente
        self.valor = valor
        self.data_inicio = datetime.strptime(data_inicio, "%d/%m/%Y")
        self.data_fim = datetime.strptime(data_fim, "%d/%m/%Y")

    def calcular_valor(self, taxa):
        total = self.valor + (self.valor * taxa)
        print(f"Valor do seguro com taxa: R$ {total:.2f}")

    def verificar_vigencia(self):
        hoje = datetime.now()
        if hoje < self.data_inicio:
            print("Seguro ainda não começou.")
        elif hoje > self.data_fim:
            print("Seguro expirado.")
        else:
            print("Seguro está na vigência.")

