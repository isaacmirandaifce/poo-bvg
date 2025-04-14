class Cliente:
    def __init__(self, nome: str, cpf: str):
        self.nome = nome
        self.cpf = cpf
        self.tipo = "N"

    def to_dict(self):
        return {
            "nome": self.nome,
            "cpf": self.cpf,
            "tipo": self.tipo
        }

class ClientePrioritario(Cliente):
    def __init__(self, nome: str, cpf: str):
        super().__init__(nome, cpf)
        self.tipo = "P"