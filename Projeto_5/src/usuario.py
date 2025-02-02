# criacação da classe Usuario
class Usuario:
       def __init__(self, nome: str, email: str, tipo: str):
        self.nome = nome
        self.email = email
        self.tipo = tipo
    
        def gerar_relatorio(self):
            raise NotImplementedError("Este método deve ser sobrescrito pelas classes derivadas.")