from abc import ABC, abstractmethod
from datetime import date
from typing import List

class Cliente:
    def __init__(self, nome: str, cpf: str):
        self.nome = nome
        self.cpf = cpf

class Veiculo:
    def __init__(self, ano: int, marca: str, modelo: str, placa: str):
        self.ano = ano
        self.marca = marca
        self.modelo = modelo
        self.placa = placa

class Carro(Veiculo):
    def __init__(self, ano: int, marca: str, modelo: str, placa: str, cor: str, portas: int):
        super().__init__(ano, marca, modelo, placa)
        self.cor = cor
        self.portas = portas

class Moto(Veiculo):
    def __init__(self, ano: int, marca: str, modelo: str, placa: str, cilindradas: int):
        super().__init__(ano, marca, modelo, placa)
        self.cilindradas = cilindradas

class SeguroVeiculo(ABC):
    """Classe base abstrata para todos os seguros de veículos"""
    
    def __init__(self, cliente: Cliente, valor: float, vigencia: date):
        self.cliente = cliente
        self.valor = valor
        self.vigencia = vigencia
    
    @abstractmethod
    def calcular_valor(self) -> float:
        """Método abstrato para calcular o valor do seguro"""
        pass
    
    def verificar_vigencia(self) -> bool:
        """Verifica se o seguro ainda está válido"""
        return self.vigencia >= date.today()
    
    def exibir_info_basica(self) -> None:
        """Exibe informações básicas do seguro"""
        print(f"Cliente: {self.cliente.nome}")
        print(f"Valor: R$ {self.valor:.2f}")
        print(f"Vigência: {self.vigencia}")
        print(f"Status: {'Válido' if self.verificar_vigencia() else 'Expirado'}")

class SeguroCarro(SeguroVeiculo):
    """Seguro específico para carros"""
    
    def __init__(self, cliente: Cliente, valor: float, vigencia: date, carro: Carro):
        super().__init__(cliente, valor, vigencia)
        self.carro = carro
        self.cobertura_roubo = False
        self.franquia = 0.0
    
    def calcular_valor(self) -> float:
        """Calcula o valor do seguro para carros"""
        # Valor base considerando idade do carro
        idade_carro = date.today().year - self.carro.ano
        valor_base = 2000.0
        
        # Fator de depreciação por idade
        if idade_carro <= 2:
            fator_idade = 1.2
        elif idade_carro <= 5:
            fator_idade = 1.0
        else:
            fator_idade = 0.8
        
        # Adicional por cobertura de roubo
        adicional_roubo = 300.0 if self.cobertura_roubo else 0.0
        
        # Desconto por franquia alta
        desconto_franquia = 0.1 if self.franquia >= 2000.0 else 0.0
        
        valor_calculado = (valor_base * fator_idade + adicional_roubo) * (1 - desconto_franquia)
        self.valor = valor_calculado
        return valor_calculado
    
    def definir_franquia(self, valor: float) -> None:
        """Define o valor da franquia"""
        self.franquia = valor
        print(f"Franquia definida em: R$ {valor:.2f}")
    
    def ativar_cobertura_roubo(self) -> None:
        """Ativa a cobertura contra roubo"""
        self.cobertura_roubo = True
        print("Cobertura contra roubo ativada")

class SeguroMoto(SeguroVeiculo):
    """Seguro específico para motos"""
    
    def __init__(self, cliente: Cliente, valor: float, vigencia: date, moto: Moto):
        super().__init__(cliente, valor, vigencia)
        self.moto = moto
        self.cobertura_capacete = False
        self.desc_cilindrada = 0.0
    
    def calcular_valor(self) -> float:
        """Calcula o valor do seguro para motos"""
        # Valor base considerando cilindradas
        if self.moto.cilindradas <= 150:
            valor_base = 800.0
        elif self.moto.cilindradas <= 300:
            valor_base = 1200.0
        else:
            valor_base = 1800.0
        
        # Idade da moto
        idade_moto = date.today().year - self.moto.ano
        fator_idade = max(0.7, 1.0 - (idade_moto * 0.05))
        
        # Adicional por cobertura de capacete
        adicional_capacete = 100.0 if self.cobertura_capacete else 0.0
        
        # Desconto por cilindrada baixa
        desconto = self.desc_cilindrada if self.moto.cilindradas <= 150 else 0.0
        
        valor_calculado = (valor_base * fator_idade + adicional_capacete) * (1 - desconto)
        self.valor = valor_calculado
        return valor_calculado
    
    def aplicar_desc_cilindrada(self, percentual: float = 0.15) -> None:
        """Aplica desconto para motos de baixa cilindrada"""
        if self.moto.cilindradas <= 150:
            self.desc_cilindrada = percentual
            print(f"Desconto de {percentual*100}% aplicado para moto de baixa cilindrada")
        else:
            print("Desconto não aplicável para motos acima de 150cc")
    
    def ativar_cobertura_capacete(self) -> None:
        """Ativa a cobertura para equipamentos de proteção"""
        self.cobertura_capacete = True
        print("Cobertura para capacete e equipamentos ativada")


# Exemplo de uso demonstrando polimorfismo
if __name__ == "__main__":
    # Criando cliente
    cliente = Cliente("Maria Santos", "987.654.321-00")
    
    # Criando veículos
    carro = Carro(2022, "Honda", "Civic", "ABC-1234", "Prata", 4)
    moto = Moto(2021, "Yamaha", "MT-03", "XYZ-5678", 321)
    
    # Criando seguros
    vigencia = date(2025, 12, 31)
    seguro_carro = SeguroCarro(cliente, 0.0, vigencia, carro)
    seguro_moto = SeguroMoto(cliente, 0.0, vigencia, moto)
    
    # Lista de seguros para demonstrar polimorfismo
    seguros: List[SeguroVeiculo] = [seguro_carro, seguro_moto]
    
    print("=== DEMONSTRAÇÃO DE POLIMORFISMO ===")
    for i, seguro in enumerate(seguros, 1):
        print(f"\nSeguro {i}:")
        print(f"Tipo: {type(seguro).__name__}")
        
        # Configurações específicas
        if isinstance(seguro, SeguroCarro):
            seguro.ativar_cobertura_roubo()
            seguro.definir_franquia(1500.0)
        elif isinstance(seguro, SeguroMoto):
            seguro.aplicar_desc_cilindrada()
            seguro.ativar_cobertura_capacete()
        
        # Chamada polimórfica do método calcular_valor
        valor = seguro.calcular_valor()
        print(f"Valor calculado: R$ {valor:.2f}")
        
        # Informações básicas (método da classe pai)
        seguro.exibir_info_basica()
        print("-" * 40)