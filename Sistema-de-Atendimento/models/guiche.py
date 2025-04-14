class Guiche:
    def __init__(self, numero):
        self.numero = numero
        self.cliente_atual = None

    def esta_disponivel(self):
        return self.cliente_atual is None

    def atender(self, senha):
        senha.status = 'em_atendimento'
        self.cliente_atual = senha

    def liberar(self):
        self.cliente_atual = None

    def to_dict(self):
        return {
            'numero': self.numero,
            'cliente_atual': self.cliente_atual.to_dict() if self.cliente_atual else None
        }
