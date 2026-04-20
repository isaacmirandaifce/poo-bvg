class Cliente:

     # Método construtor: executado sempre que um novo objeto Cliente é criado
     #o __init__ cria e inicializa os atributos do objeto no momento em que ele nasce.
    def __init__(self, nomeDoCliente, idadeCliente, saldoCliente):
        self.nomeDoCliente = nomeDoCliente
        self.idadeCliente = idadeCliente
        self.saldoCliente = saldoCliente


    # Método para mostrar as informações do cliente
    def mostrarInformacoes(self):

    #Mostra os dados no terminal
        print(f"Cliente: {self.nomeDoCliente}, Idade: {self.idadeCliente}, Saldo: {self.saldoCliente}")
    
    # Método para atualizar o saldo do cliente
    def atualizarSaldo(self, valor):

    #Atualiza o saldo do cliente com o valor passado como parâmetro 
        self.saldoCliente += valor



