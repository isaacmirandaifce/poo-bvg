#Criando a classe cliente
class Cliente:
    #Criado uma funcao com o comando 'self', que possibilida o acesso dos atributos objetos 
    def __init__(self, nome, idade, saldo): 
        self.nome = nome
        self.idade = idade
        self.saldo = saldo


# Método para exibir as informações do cliente, incluindo nome, idade e saldo, formatados em uma string legível.
    def showInfor(self):
        print(f"Cliente: {self.nome}, tem {self.idade} anos de idade e possui um saldo de: R$ {self.saldo}")
    
# Método que atualiza o vaor do saldo 
    def updateSaldo(self, valor):
        self.saldo += valor
        print(f"Saldo atualizado para: R$ {valor}")
