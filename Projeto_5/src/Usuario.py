class Usuario:
    def __init__(self, nome, email, tipo):
        self.nome = nome
        self.email = email
        self.tipo = tipo

    def gerar_relatorio(self):
        raise NotImplementedError("Este método deve ser sobrescrito nas classes derivadas")
