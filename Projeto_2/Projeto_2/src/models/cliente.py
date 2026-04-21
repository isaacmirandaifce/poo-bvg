class Cliente:
    def __init__(self, nome: str, cpf: str, email: str) -> None:
        self.__nome = nome
        self.__cpf = cpf
        self.__email = email

    def get_nome(self) -> str:
        return self.__nome

    def get_cpf_mascarado(self) -> str:
        cpf = self.__cpf.replace(".", "").replace("-", "")
        return f"{cpf[:3]}.***.***.{cpf[-2:]}"

    def get_email(self) -> str:
        return self.__email

    def __str__(self) -> str:
        return f"Cliente: {self.__nome} | CPF: {self.get_cpf_mascarado()} | E-mail: {self.__email}"
