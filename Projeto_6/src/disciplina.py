class Disciplina:
    def __init__(self, nome: str, carga_horaria: int):
        # Inicializa a disciplina com nome, carga horária e nota inicial como privada
        self.nome = nome
        self.carga_horaria = carga_horaria
        self.__nota = 0.0

    def set_nota(self, nota: float):
        # Define a nota da disciplina com validação para garantir valores entre 0 e 10
        if 0.0 <= nota <= 10.0:
            self.__nota = nota
        else:
            print("Nota inválida. Deve estar entre 0 e 10.")

    def get_nota(self):
        # Retorna a nota da disciplina
        return self.__nota
