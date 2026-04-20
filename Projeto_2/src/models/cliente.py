class Cliente:
    def __init__(self, nome, cpf):
        self.nome = nome
        self._cpf = cpf
        self.seguros = []

    def adicionar_seguro(self, seguro):
        self.seguros.append(seguro)

    def listar_seguros(self):
        return self.seguros