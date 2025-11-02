class Cliente:
    
    """Classe Cliente com CPF encapsulado."""
    
    def __init__(self, nome: str, cpf: str):
        self.__nome = nome
        self.__cpf = cpf  

    def exibir_informacoes(self) -> str:
        
        return f"Cliente: {self.__nome}, CPF: {self.obter_cpf_mascarado()}"

    def obter_cpf_mascarado(self) -> str:
        
        # mascarar o CPF para não expor todos os dígitos
        
        return f"***.***.***-{self.__cpf[-2:]}"

    @property
    def nome(self):
        
        return self.__nome