from models.cliente import Cliente, ClientePrioritario

def criar_cliente(nome, cpf, tipo):
    if tipo == 'P':
        return ClientePrioritario(nome, cpf)
    return Cliente(nome, cpf)
