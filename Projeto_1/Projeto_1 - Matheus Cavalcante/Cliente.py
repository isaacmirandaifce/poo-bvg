class Cliente():
    def __init__(self, nome, idade, saldo):
        self.nome = nome
        self.idade = idade
        self.saldo = saldo

    def mostrar_informacoes(self):
        print(f"Cliente: {self.nome}, Idade: {self.idade}, Saldo: {self.saldo}")

    def atualizar_saldo(self, valor):
        self.saldo += valor
        print(f"Saldo atualizado: R${self.saldo:.2f}")

#cliente1 = Cliente("João Silva", 30, 1000.0)
#cliente1.mostrar_informacoes()
#cliente1.atualizar_saldo(500.0)
#cliente1.mostrar_informacoes()
