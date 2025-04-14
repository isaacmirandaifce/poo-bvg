from datetime import datetime
class Senha:
    contador = {'N': 0, 'P': 0}

    def __init__(self, cliente, tipo):
        self.cliente = cliente
        self.tipo = tipo
        self.status = 'aguardando'
        Senha.contador[self.tipo] += 1
        self.numero = f"{self.tipo}{Senha.contador[self.tipo]:03d}"
        self.data = datetime.now().strftime('%Y-%m-%d %H:%M:%S')

    def __lt__(self, other):
        if self.tipo != other.tipo:
            return self.tipo == 'P'
        return self.numero < other.numero

    def to_dict(self):
        return {
            'numero': self.numero,
            'tipo': self.tipo,
            'status': self.status,
            'data': self.data,
            'cliente': self.cliente.to_dict()
        }