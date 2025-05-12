class Cliente:
    # classe Cliente criada

    def __init__(self, nome, idade, saldo):
        # encapsulamento
        self.nome = nome
        self.idade = idade
        self.saldo = saldo

    def mostrar_informacoes(self):
        # modularidade
        print(f"Cliente: {self.nome}, Idade: {self.idade}, Saldo: R${self.saldo:.2f}")

    def atualizar_saldo(self, valor):
        # Atualização dos saldos
        self.saldo += valor