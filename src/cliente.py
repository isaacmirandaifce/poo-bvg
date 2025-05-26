class Cliente:
    def __init__(self, nome, idade, saldo, cpf):
        self.nome = nome
        self.idade = idade
        self.saldo = saldo
        self.cpf = cpf

    def mostrar_informacoes(self):
        print(f"Cliente: {self.nome}, Idade: {self.idade}, CPF: {self.cpf}, Saldo: R${self.saldo:.2f}")

    def atualizar_saldo(self, valor):
        self.saldo += valor

    def exibir_informacoes(self):
        info = f"Nome: {self.nome} | CPF: {self.cpf}"
        print(info)
        return info
