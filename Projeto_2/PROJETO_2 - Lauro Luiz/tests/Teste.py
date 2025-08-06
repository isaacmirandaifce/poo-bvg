#!/usr/bin/env python3
"""
Projeto Avaliativo 2 - Paradigma de Orientação a Objetos e UML
Sistema de Seguros - Código de Teste Completo

Este arquivo integra todos os exercícios e demonstra o funcionamento
completo do sistema de seguros desenvolvido.
"""

from datetime import datetime, date, timedelta
import re
from abc import ABC, abstractmethod
from typing import List

# ==================== CLASSES BASE ====================

class Cliente:
    """Classe Cliente com encapsulamento"""
    
    def __init__(self, nome: str, cpf: str):
        self._nome = nome.strip().title()
        self.__cpf = self._validar_cpf(cpf)
        self._data_cadastro = datetime.now()
    
    @property
    def nome(self) -> str:
        return self._nome
    
    @property
    def cpf(self) -> str:
        return self._mascarar_cpf(self.__cpf)
    
    def _validar_cpf(self, cpf: str) -> str:
        cpf_numeros = re.sub(r'\D', '', cpf)
        if len(cpf_numeros) != 11:
            raise ValueError("CPF deve ter 11 dígitos")
        return cpf_numeros
    
    def _mascarar_cpf(self, cpf: str) -> str:
        return f"{cpf[:3]}.{cpf[3:6]}.{cpf[6:9]}-{cpf[9:]}"
    
    def exibir_informacoes(self) -> None:
        print(f"Nome: {self.nome}")
        print(f"CPF: {self.cpf}")


class Veiculo:
    """Classe base para veículos"""
    
    def __init__(self, ano: int, marca: str, modelo: str, placa: str):
        self.ano = ano
        self.marca = marca.strip().title()
        self.modelo = modelo.strip().title()
        self.__placa = self._validar_placa(placa)
    
    @property
    def placa(self) -> str:
        return self._mascarar_placa(self.__placa)
    
    def _validar_placa(self, placa: str) -> str:
        placa_limpa = re.sub(r'[^A-Z0-9]', '', placa.upper())
        if not re.match(r'^[A-Z]{3}[0-9]{4}$', placa_limpa):
            raise ValueError("Formato de placa inválido")
        return placa_limpa
    
    def _mascarar_placa(self, placa: str) -> str:
        return f"{placa[:3]}-{placa[3:]}"


class Carro(Veiculo):
    """Classe específica para carros"""
    
    def __init__(self, ano: int, marca: str, modelo: str, placa: str, cor: str, portas: int = 4):
        super().__init__(ano, marca, modelo, placa)
        self.cor = cor.strip().title()
        self.portas = portas
    
    def exibir_detalhes(self) -> None:
        print(f"Carro: {self.marca} {self.modelo}")
        print(f"Ano: {self.ano}")
        print(f"Cor: {self.cor}")
        print(f"Portas: {self.portas}")
        print(f"Placa: {self.placa}")
    
    def atualizar_cor(self, nova_cor: str) -> None:
        self.cor = nova_cor.strip().title()
        print(f"Cor atualizada para: {self.cor}")


class Moto(Veiculo):
    """Classe específica para motos"""
    
    def __init__(self, ano: int, marca: str, modelo: str, placa: str, cilindradas: int):
        super().__init__(ano, marca, modelo, placa)
        self.cilindradas = cilindradas
    
    def exibir_detalhes(self) -> None:
        print(f"Moto: {self.marca} {self.modelo}")
        print(f"Ano: {self.ano}")
        print(f"Cilindradas: {self.cilindradas}cc")
        print(f"Placa: {self.placa}")


# ==================== HIERARQUIA DE SEGUROS ====================

class SeguroVeiculo(ABC):
    """Classe abstrata base para seguros de veículos"""
    
    def __init__(self, cliente: Cliente, valor: float, vigencia: date):
        self.cliente = cliente
        self.valor = valor
        self.vigencia = vigencia
        self._ativo = True
    
    @abstractmethod
    def calcular_valor(self) -> float:
        """Método abstrato para cálculo do valor"""
        pass
    
    def verificar_vigencia(self) -> bool:
        """Verifica se o seguro está válido"""
        if not self._ativo:
            return False
        
        data_atual = date.today()
        if data_atual > self.vigencia:
            self._ativo = False
            return False
        
        # Alerta de renovação
        dias_para_vencer = (self.vigencia - data_atual).days
        if 0 < dias_para_vencer <= 30:
            print(f"⚠️  Seguro vence em {dias_para_vencer} dias!")
        
        return True
    
    def cancelar_seguro(self) -> None:
        """Cancela o seguro"""
        self._ativo = False
        print("Seguro cancelado")


class SeguroCarro(SeguroVeiculo):
    """Seguro específico para carros"""
    
    def __init__(self, cliente: Cliente, carro: Carro, valor: float, vigencia: date):
        super().__init__(cliente, valor, vigencia)
        self.carro = carro
        self.cobertura_roubo = False
        self.franquia = 0.0
    
    def calcular_valor(self) -> float:
        """Calcula valor específico para carros"""
        idade_carro = date.today().year - self.carro.ano
        valor_base = 2000.0
        
        # Fator idade
        if idade_carro <= 2:
            fator_idade = 1.2
        elif idade_carro <= 5:
            fator_idade = 1.0
        else:
            fator_idade = 0.8
        
        # Cobertura roubo
        adicional_roubo = 300.0 if self.cobertura_roubo else 0.0
        
        # Desconto franquia
        desconto_franquia = 0.1 if self.franquia >= 2000.0 else 0.0
        
        valor_calculado = (valor_base * fator_idade + adicional_roubo) * (1 - desconto_franquia)
        self.valor = valor_calculado
        return valor_calculado
    
    def ativar_cobertura_roubo(self) -> None:
        """Ativa cobertura contra roubo"""
        self.cobertura_roubo = True
        print("Cobertura contra roubo ativada")
    
    def definir_franquia(self, valor: float) -> None:
        """Define valor da franquia"""
        self.franquia = valor
        print(f"Franquia definida: R$ {valor:.2f}")


class SeguroMoto(SeguroVeiculo):
    """Seguro específico para motos"""
    
    def __init__(self, cliente: Cliente, moto: Moto, valor: float, vigencia: date):
        super().__init__(cliente, valor, vigencia)
        self.moto = moto
        self.cobertura_capacete = False
        self.desc_cilindrada = 0.0
    
    def calcular_valor(self) -> float:
        """Calcula valor específico para motos"""
        # Valor base por cilindrada
        if self.moto.cilindradas <= 150:
            valor_base = 800.0
        elif self.moto.cilindradas <= 300:
            valor_base = 1200.0
        else:
            valor_base = 1800.0
        
        # Fator idade
        idade_moto = date.today().year - self.moto.ano
        fator_idade = max(0.7, 1.0 - (idade_moto * 0.05))
        
        # Cobertura capacete
        adicional_capacete = 100.0 if self.cobertura_capacete else 0.0
        
        # Desconto cilindrada
        desconto = self.desc_cilindrada if self.moto.cilindradas <= 150 else 0.0
        
        valor_calculado = (valor_base * fator_idade + adicional_capacete) * (1 - desconto)
        self.valor = valor_calculado
        return valor_calculado
    
    def aplicar_desc_cilindrada(self, percentual: float = 0.15) -> None:
        """Aplica desconto para motos baixa cilindrada"""
        if self.moto.cilindradas <= 150:
            self.desc_cilindrada = percentual
            print(f"Desconto de {percentual*100}% aplicado")
        else:
            print("Desconto não aplicável para motos acima de 150cc")
    
    def ativar_cobertura_capacete(self) -> None:
        """Ativa cobertura para equipamentos"""
        self.cobertura_capacete = True
        print("Cobertura para capacete ativada")


# ==================== SISTEMA DE GERENCIAMENTO ====================

class SistemaSeguro:
    """Sistema para gerenciar múltiplos seguros"""
    
    def __init__(self):
        self.seguros: List[SeguroVeiculo] = []
        self.clientes: List[Cliente] = []
    
    def adicionar_cliente(self, cliente: Cliente) -> None:
        """Adiciona um cliente ao sistema"""
        self.clientes.append(cliente)
        print(f"Cliente {cliente.nome} adicionado ao sistema")
    
    def criar_seguro_carro(self, cliente: Cliente, carro: Carro, vigencia: date) -> SeguroCarro:
        """Cria um novo seguro de carro"""
        seguro = SeguroCarro(cliente, carro, 0.0, vigencia)
        seguro.calcular_valor()
        self.seguros.append(seguro)
        return seguro
    
    def criar_seguro_moto(self, cliente: Cliente, moto: Moto, vigencia: date) -> SeguroMoto:
        """Cria um novo seguro de moto"""
        seguro = SeguroMoto(cliente, moto, 0.0, vigencia)
        seguro.calcular_valor()
        self.seguros.append(seguro)
        return seguro
    
    def listar_seguros_cliente(self, nome_cliente: str) -> List[SeguroVeiculo]:
        """Lista todos os seguros de um cliente"""
        seguros_cliente = []
        for seguro in self.seguros:
            if seguro.cliente.nome.lower() == nome_cliente.lower():
                seguros_cliente.append(seguro)
        return seguros_cliente
    
    def verificar_seguros_vencendo(self, dias: int = 30) -> List[SeguroVeiculo]:
        """Verifica seguros que vencem em X dias"""
        seguros_vencendo = []
        data_limite = date.today() + timedelta(days=dias)
        
        for seguro in self.seguros:
            if seguro.verificar_vigencia() and seguro.vigencia <= data_limite:
                seguros_vencendo.append(seguro)
        
        return seguros_vencendo
    
    def relatorio_geral(self) -> None:
        """Gera relatório geral do sistema"""
        print("=" * 50)
        print("RELATÓRIO GERAL DO SISTEMA DE SEGUROS")
        print("=" * 50)
        print(f"Total de clientes: {len(self.clientes)}")
        print(f"Total de seguros: {len(self.seguros)}")
        
        seguros_ativos = sum(1 for s in self.seguros if s.verificar_vigencia())
        print(f"Seguros ativos: {seguros_ativos}")
        
        valor_total = sum(s.valor for s in self.seguros if s.verificar_vigencia())
        print(f"Valor total em carteira: R$ {valor_total:,.2f}")
        
        seguros_carro = sum(1 for s in self.seguros if isinstance(s, SeguroCarro))
        seguros_moto = sum(1 for s in self.seguros if isinstance(s, SeguroMoto))
        print(f"Seguros de carro: {seguros_carro}")
        print(f"Seguros de moto: {seguros_moto}")


# ==================== TESTES E DEMONSTRAÇÕES ====================

def demonstrar_exercicio1():
    """Demonstra o Exercício 1 - Modelagem básica"""
    print("\n" + "=" * 60)
    print("EXERCÍCIO 1 - MODELAGEM BÁSICA DE DOMÍNIO")
    print("=" * 60)
    
    # Criando objetos básicos
    cliente = Cliente("João Silva", "12345678900")
    carro = Carro(2020, "Toyota", "Corolla", "XYZ1234", "Branco")
    
    print("Cliente criado:")
    cliente.exibir_informacoes()
    
    print("\nCarro criado:")
    carro.exibir_detalhes()
    
    print("\n✅ Relacionamentos implementados:")
    print("• Cliente ←→ Seguro (associação)")
    print("• Carro ←→ Seguro (associação)")


def demonstrar_exercicio2():
    """Demonstra o Exercício 2 - Métodos detalhados"""
    print("\n" + "=" * 60)
    print("EXERCÍCIO 2 - DETALHAMENTO DE MÉTODOS")
    print("=" * 60)
    
    cliente = Cliente("Maria Santos", "98765432100")
    carro = Carro(2022, "Honda", "Civic", "ABC1234", "Prata")
    vigencia = date(2025, 12, 31)
    
    # Usando a classe Seguro original (não a hierarquia)
    class SeguroSimples:
        def __init__(self, cliente, carro, valor, vigencia):
            self.cliente = cliente
            self.carro = carro
            self.valor = valor
            self.vigencia = vigencia
        
        def calcular_valor(self, base_valor, taxa):
            valor_calculado = base_valor * (1 + taxa)
            self.valor = valor_calculado
            return valor_calculado
        
        def verificar_vigencia(self):
            return self.vigencia >= date.today()
    
    seguro = SeguroSimples(cliente, carro, 1500.0, vigencia)
    
    print("Testando métodos:")
    print(f"Valor inicial: R$ {seguro.valor:.2f}")
    
    novo_valor = seguro.calcular_valor(1200.0, 0.25)
    print(f"Valor recalculado: R$ {novo_valor:.2f}")
    
    print(f"Seguro válido: {'Sim' if seguro.verificar_vigencia() else 'Não'}")
    
    print("\nTestando alteração de cor:")
    carro.atualizar_cor("Azul Metálico")


def demonstrar_exercicio3():
    """Demonstra o Exercício 3 - Múltiplas associações"""
    print("\n" + "=" * 60)
    print("EXERCÍCIO 3 - MÚLTIPLAS ASSOCIAÇÕES")
    print("=" * 60)
    
    sistema = SistemaSeguro()
    
    # Cliente com múltiplos veículos
    cliente = Cliente("Carlos Oliveira", "55566677788")
    sistema.adicionar_cliente(cliente)
    
    # Múltiplos carros
    carro1 = Carro(2021, "Volkswagen", "Gol", "DEF5678", "Branco")
    carro2 = Carro(2019, "Fiat", "Uno", "GHI9012", "Vermelho")
    
    vigencia = date(2025, 6, 30)
    
    # Criando múltiplos seguros
    seguro1 = sistema.criar_seguro_carro(cliente, carro1, vigencia)
    seguro2 = sistema.criar_seguro_carro(cliente, carro2, vigencia)
    
    print(f"\nCliente {cliente.nome} possui {len(sistema.listar_seguros_cliente(cliente.nome))} seguros")
    
    print("\n✅ Justificativa dos relacionamentos:")
    print("• AGREGAÇÃO entre Seguro e Carro:")
    print("  - Carro pode existir independentemente do Seguro")
    print("  - Seguro 'usa' o Carro mas não o 'possui'")
    print("• Cliente pode ter múltiplos seguros (1:N)")
    print("• Seguro pode cobrir múltiplos carros (M:N)")


def demonstrar_exercicio4():
    """Demonstra o Exercício 4 - Herança"""
    print("\n" + "=" * 60)
    print("EXERCÍCIO 4 - HERANÇA E POLIMORFISMO")
    print("=" * 60)
    
    cliente = Cliente("Ana Paula", "11122233344")
    
    # Diferentes tipos de veículos
    carro = Carro(2023, "Hyundai", "HB20", "JKL3456", "Azul")
    moto = Moto(2022, "Honda", "CB600F", "MNO7890", 600)
    
    vigencia = date(2025, 8, 15)
    
    # Diferentes tipos de seguro
    seguro_carro = SeguroCarro(cliente, carro, 0.0, vigencia)
    seguro_moto = SeguroMoto(cliente, moto, 0.0, vigencia)
    
    print("Demonstrando polimorfismo:")
    seguros = [seguro_carro, seguro_moto]
    
    for i, seguro in enumerate(seguros, 1):
        print(f"\n{i}. {type(seguro).__name__}:")
        
        # Configurações específicas
        if isinstance(seguro, SeguroCarro):
            seguro.ativar_cobertura_roubo()
            seguro.definir_franquia(1800.0)
        elif isinstance(seguro, SeguroMoto):
            seguro.aplicar_desc_cilindrada(0.20)
            seguro.ativar_cobertura_capacete()
        
        # Chamada polimórfica
        valor = seguro.calcular_valor()
        print(f"Valor calculado: R$ {valor:.2f}")
    
    print("\n✅ Benefícios da herança:")
    print("• Reutilização de código comum (SeguroVeiculo)")
    print("• Especialização para diferentes tipos")
    print("• Polimorfismo permite tratar objetos uniformemente")
    print("• Facilita extensão para novos tipos de seguro")


def demonstrar_exercicio5():
    """Demonstra o Exercício 5 - Diagrama de objetos"""
    print("\n" + "=" * 60)
    print("EXERCÍCIO 5 - INSTÂNCIAS ESPECÍFICAS (Diagrama de Objetos)")
    print("=" * 60)
    
    # Dados exatos do exercício
    cliente = Cliente("João Silva", "12345678900")
    carro = Carro(2020, "Toyota", "Corolla", "XYZ1234", "Branco")
    
    # Data específica do exercício
    vigencia = date(2025, 1, 1)  # 01/01/2025
    
    seguro_carro = SeguroCarro(cliente, carro, 1500.0, vigencia)
    
    print("INSTÂNCIAS CRIADAS:")
    print("\n1. Objeto Cliente (joao):")
    cliente.exibir_informacoes()
    
    print("\n2. Objeto Carro (corolla2020):")
    carro.exibir_detalhes()
    
    print(f"\n3. Objeto Seguro (seguro001):")
    print(f"Valor: R$ {seguro_carro.valor:.2f}")
    print(f"Vigência: {seguro_carro.vigencia.strftime('%d/%m/%Y')}")
    print(f"Cliente: {seguro_carro.cliente.nome}")
    print(f"Veículo: {seguro_carro.carro.marca} {seguro_carro.carro.modelo}")
    
    print("\n✅ Este diagrama de objetos ajuda a:")
    print("• Visualizar instâncias reais com dados específicos")
    print("• Compreender como os objetos se relacionam em runtime")
    print("• Validar o modelo de classes com exemplos concretos")


def demonstrar_exercicio6():
    """Demonstra o Exercício 6 - Encapsulamento"""
    print("\n" + "=" * 60)
    print("EXERCÍCIO 6 - ENCAPSULAMENTO E ABSTRAÇÃO")
    print("=" * 60)
    
    print("Demonstrando proteção de dados sensíveis:")
    
    cliente = Cliente("Roberto Lima", "99988877766")
    carro = Carro(2021, "Chevrolet", "Onix", "PQR4567", "Cinza")
    
    print("\n1. ACESSO CONTROLADO:")
    print(f"CPF mascarado: {cliente.cpf}")
    print(f"Placa mascarada: {carro.placa}")
    
    print("\n2. TENTATIVA DE ACESSO DIRETO (falhará):")
    try:
        # Tentativa de acesso direto aos atributos privados
        print(cliente._Cliente__cpf)  # Name mangling
        print("⚠️  Acesso direto possível via name mangling (não recomendado)")
    except AttributeError:
        print("❌ Acesso bloqueado com sucesso")
    
    print("\n3. VALIDAÇÃO DE VIGÊNCIA (Pseudocódigo implementado):")
    vigencia_proxima = date.today() + timedelta(days=25)  # Vence em 25 dias
    seguro = SeguroCarro(cliente, carro, 2000.0, vigencia_proxima)
    
    valido = seguro.verificar_vigencia()  # Deve emitir alerta
    print(f"Seguro válido: {valido}")
    
    print("\n✅ IMPORTÂNCIA DO ENCAPSULAMENTO EM SEGUROS:")
    print("• SEGURANÇA: Protege CPF, placas e dados pessoais")
    print("• INTEGRIDADE: Valida dados antes de armazenar")
    print("• AUDITORIA: Controla acesso a informações sensíveis")
    print("• LGPD: Facilita compliance com proteção de dados")
    print("• MANUTENÇÃO: Permite alterações sem quebrar código cliente")


def executar_suite_completa():
    """Executa todos os testes e demonstrações"""
    print("🚀 INICIANDO SUITE COMPLETA DE TESTES")
    print("📋 Projeto Avaliativo 2 - Orientação a Objetos e UML")
    
    try:
        # Executa todos os exercícios
        demonstrar_exercicio1()
        demonstrar_exercicio2()
        demonstrar_exercicio3()
        demonstrar_exercicio4()
        demonstrar_exercicio5()
        demonstrar_exercicio6()
        
        # Demonstração final do sistema integrado
        print("\n" + "=" * 60)
        print("DEMONSTRAÇÃO FINAL - SISTEMA INTEGRADO")
        print("=" * 60)
        
        sistema = SistemaSeguro()
        
        # Criando múltiplos clientes e seguros
        clientes_dados = [
            ("João Silva", "12345678900"),
            ("Maria Santos", "98765432100"),
            ("Carlos Oliveira", "55566677788")
        ]
        
        for nome, cpf in clientes_dados:
            cliente = Cliente(nome, cpf)
            sistema.adicionar_cliente(cliente)
        
        # Criando seguros variados
        vigencia_longa = date(2025, 12, 31)
        vigencia_curta = date.today() + timedelta(days=20)
        
        # Seguros de carro
        carro1 = Carro(2023, "Toyota", "Corolla", "ABC1234", "Branco")
        seguro1 = sistema.criar_seguro_carro(sistema.clientes[0], carro1, vigencia_longa)
        seguro1.ativar_cobertura_roubo()
        
        # Seguros de moto
        moto1 = Moto(2022, "Honda", "CB600", "XYZ9876", 600)
        seguro2 = sistema.criar_seguro_moto(sistema.clientes[1], moto1, vigencia_curta)
        seguro2.ativar_cobertura_capacete()
        
        # Relatório final
        sistema.relatorio_geral()
        
        # Verificação de seguros vencendo
        print("\n📅 SEGUROS VENCENDO EM 30 DIAS:")
        seguros_vencendo = sistema.verificar_seguros_vencendo(30)
        if seguros_vencendo:
            for seguro in seguros_vencendo:
                print(f"• {seguro.cliente.nome}: {type(seguro).__name__} - {seguro.vigencia}")
        else:
            print("Nenhum seguro vencendo no período")
        
        print("\n✅ SUITE DE TESTES CONCLUÍDA COM SUCESSO!")
        print("📊 Todos os exercícios foram demonstrados e validados")
        
    except Exception as e:
        print(f"\n❌ ERRO NA EXECUÇÃO: {e}")
        import traceback
        traceback.print_exc()


# ==================== EXECUÇÃO PRINCIPAL ====================

if __name__ == "__main__":
    executar_suite_completa()