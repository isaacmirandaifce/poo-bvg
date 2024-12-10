from dataclasses import dataclass

# Criação da Classe Carro
@dataclass
class Carro:
    ano: int
    marca: str
    modelo: str
    cor: str
    placa: str

# Método para exibir os detalhes do Carro
    def exibir_detalhes(self):
        print(f"Carro: {self.marca} {self.modelo} ({self.ano})")
        print(f"Cor: {self.cor}")
        print(f"Placa: {self.placa}")

# Método para atualizar a cor do carro
    def atualizar_cor(self, nova_cor):
        self.cor = nova_cor
        print(f"A cor do carro foi atualizada para: {self.cor}")