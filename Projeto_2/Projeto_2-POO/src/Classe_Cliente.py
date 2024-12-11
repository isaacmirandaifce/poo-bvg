# Definição da classe Cliente:
class Cliente:
    # Método construtor para inicializar os atributos do cliente:
    def __init__(self, nome, cpf):
        self.__nome = nome
        self._cpf = cpf
        self.seguros = []

    # Método para obter o CPF do cliente:
    def get_cpf(self):
        return self._cpf

    # Método para definir o CPF do cliente, com validação:
    def set_cpf(self, cpf):
        if isinstance(cpf, str) and len(cpf) == 14 and cpf.count(".") == 2 and cpf.count("-") == 1:
            self._cpf = cpf
        else:
            print("CPF inválido!")

    # Método para adicionar um seguro à lista de seguros do cliente:
    def adicionar_seguro(self, seguro):
        self.seguros.append(seguro)

    # Método para exibir as informações do cliente:
    def exibir_informacoes(self):
        print(f"Nome: {self.__nome}, CPF: {self.get_cpf()}")
        print("Seguros Ativos:")
        if not self.seguros:
            print("Nenhum seguro ativo.")
        else:
            for seguro in self.seguros:
                seguro.exibir_informacoes()

# Definição da classe Seguro:
class Seguro:
    # Método construtor para inicializar os atributos do seguro:
    def __init__(self, valor, vigencia):
        self._valor = valor
        self._vigencia = vigencia

    # Método para exibir as informações do seguro:
    def exibir_informacoes(self):
        print(f"Valor: R$ {self._valor:.2f}, Vigência: {self._vigencia}")
