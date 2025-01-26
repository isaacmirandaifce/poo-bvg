class Usuario:
    def __init__(self, nome: str, email: str):
        # Inicializa os atributos básicos do usuário
        self.nome = nome
        self.email = email

    def gerar_relatorio(self):
        # Método abstrato para gerar relatórios (deve ser sobrescrito)
        raise NotImplementedError("Este método deve ser implementado nas subclasses.")
