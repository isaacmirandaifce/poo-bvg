class Disciplina:
    
    #Metodo construtor de disciplina
    def __init__(self, nome, carga_horaria):
        self.nome = nome
        self.carga_horaria = carga_horaria
        self.__nota = 0.0  # Atributo privado

        """Atribuição de notas"""
    def set_nota(self, nota):
        if 0.0 <= nota <= 10.0:
            self.__nota = nota
        else:
            print("Nota inválida. Deve estar entre 0 e 10.")

    #Pega a nota
    def get_nota(self):
        return self.__nota
