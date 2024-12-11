from dataclasses import dataclass

# Criação da Classe Cliente
@dataclass
class Cliente:
    nome: str
    cpf: str

# Método para exibir as informações do Cliente
    def exibir_informacoes(self):
        print(f"Cliente: {self.nome}")
        print(f"CPF: {self.cpf}")