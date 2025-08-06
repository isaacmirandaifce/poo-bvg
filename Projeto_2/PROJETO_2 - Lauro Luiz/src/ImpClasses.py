from datetime import datetime, date

class Cliente:
    """Classe que representa um cliente do sistema de seguros"""
    
    def __init__(self, nome: str, cpf: str):
        self.nome = nome
        self.cpf = cpf
    
    def exibir_informacoes(self) -> None:
        """Exibe as informações do cliente"""
        print(f"Cliente: {self.nome}")
        print(f"CPF: {self.cpf}")


class Carro:
    """Classe que representa um carro no sistema de seguros"""
    
    def __init__(self, ano: int, marca: str, modelo: str, cor: str, placa: str):
        self.ano = ano
        self.marca = marca
        self.modelo = modelo
        self.cor = cor
        self.placa = placa
    
    def exibir_detalhes(self) -> None:
        """Exibe as informações detalhadas do carro"""
        print(f"Carro: {self.marca} {self.modelo}")
        print(f"Ano: {self.ano}")
        print(f"Cor: {self.cor}")
        print(f"Placa: {self.placa}")
    
    def atualizar_cor(self, nova_cor: str) -> None:
        """Atualiza a cor do carro"""
        self.cor = nova_cor
        print(f"Cor do carro atualizada para: {nova_cor}")


class Seguro:
    """Classe que representa um seguro de carro"""
    
    def __init__(self, carro: Carro, cliente: Cliente, valor: float, vigencia: date):
        self.carro = carro
        self.cliente = cliente
        self.valor = valor
        self.vigencia = vigencia
    
    def calcular_valor(self, base_valor: float, taxa: float) -> float:
        """Calcula o valor do seguro com base em um valor base e uma taxa"""
        valor_calculado = base_valor * (1 + taxa)
        self.valor = valor_calculado
        return valor_calculado
    
    def verificar_vigencia(self) -> bool:
        """Retorna se o seguro ainda está válido"""
        data_atual = date.today()
        return self.vigencia >= data_atual


# Exemplo de uso das classes
if __name__ == "__main__":
    # Criando um cliente
    cliente1 = Cliente("João Silva", "123.456.789-00")
    
    # Criando um carro
    carro1 = Carro(2020, "Toyota", "Corolla", "Branco", "XYZ-1234")
    
    # Criando um seguro
    vigencia_seguro = date(2025, 1, 1)
    seguro1 = Seguro(carro1, cliente1, 1500.0, vigencia_seguro)
    
    # Testando os métodos
    print("=== INFORMAÇÕES DO CLIENTE ===")
    cliente1.exibir_informacoes()
    
    print("\n=== DETALHES DO CARRO ===")
    carro1.exibir_detalhes()
    
    print(f"\n=== INFORMAÇÕES DO SEGURO ===")
    print(f"Valor atual: R$ {seguro1.valor:.2f}")
    print(f"Vigência: {seguro1.vigencia}")
    print(f"Seguro válido: {'Sim' if seguro1.verificar_vigencia() else 'Não'}")
    
    print("\n=== CALCULANDO NOVO VALOR ===")
    novo_valor = seguro1.calcular_valor(1200.0, 0.25)
    print(f"Novo valor calculado: R$ {novo_valor:.2f}")
    
    print("\n=== ATUALIZANDO COR DO CARRO ===")
    carro1.atualizar_cor("Azul")
    carro1.exibir_detalhes()