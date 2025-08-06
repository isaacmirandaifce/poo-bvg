from datetime import datetime, date
import re

class Cliente:
    """Classe Cliente com encapsulamento de informações sensíveis"""
    
    def __init__(self, nome: str, cpf: str):
        self._nome = nome
        self.__cpf = self._validar_cpf(cpf)  # Atributo privado
        self._data_cadastro = datetime.now()
    
    @property
    def nome(self) -> str:
        """Getter para o nome do cliente"""
        return self._nome
    
    @nome.setter
    def nome(self, novo_nome: str) -> None:
        """Setter para o nome com validação"""
        if len(novo_nome.strip()) < 2:
            raise ValueError("Nome deve ter pelo menos 2 caracteres")
        self._nome = novo_nome.strip().title()
    
    @property
    def cpf(self) -> str:
        """Getter para CPF - retorna versão mascarada"""
        return self._mascarar_cpf(self.__cpf)
    
    def _validar_cpf(self, cpf: str) -> str:
        """Método privado para validar formato do CPF"""
        # Remove caracteres não numéricos
        cpf_numeros = re.sub(r'\D', '', cpf)
        
        if len(cpf_numeros) != 11:
            raise ValueError("CPF deve ter 11 dígitos")
        
        # Validação simples (não inclui verificação de dígitos verificadores)
        if cpf_numeros == cpf_numeros[0] * 11:
            raise ValueError("CPF inválido")
        
        return cpf_numeros
    
    def _mascarar_cpf(self, cpf: str) -> str:
        """Método privado para mascarar o CPF"""
        return f"{cpf[:3]}.{cpf[3:6]}.{cpf[6:9]}-{cpf[9:]}"
    
    def verificar_cpf(self, cpf_informado: str) -> bool:
        """Método público para verificar se o CPF informado corresponde ao cadastrado"""
        try:
            cpf_validado = self._validar_cpf(cpf_informado)
            return cpf_validado == self.__cpf
        except ValueError:
            return False
    
    def exibir_informacoes(self) -> None:
        """Exibe informações do cliente de forma segura"""
        print(f"Nome: {self.nome}")
        print(f"CPF: {self.cpf}")  # CPF mascarado
        print(f"Data de Cadastro: {self._data_cadastro.strftime('%d/%m/%Y')}")


class Carro:
    """Classe Carro com encapsulamento de informações do veículo"""
    
    def __init__(self, ano: int, marca: str, modelo: str, cor: str, placa: str):
        self._ano = self._validar_ano(ano)
        self._marca = marca.strip().title()
        self._modelo = modelo.strip().title()
        self._cor = cor.strip().title()
        self.__placa = self._validar_placa(placa)  # Atributo privado
    
    @property
    def ano(self) -> int:
        return self._ano
    
    @property
    def marca(self) -> str:
        return self._marca
    
    @property
    def modelo(self) -> str:
        return self._modelo
    
    @property
    def cor(self) -> str:
        return self._cor
    
    @cor.setter
    def cor(self, nova_cor: str) -> None:
        """Permite alterar a cor do veículo"""
        self._cor = nova_cor.strip().title()
    
    @property
    def placa(self) -> str:
        """Retorna placa mascarada"""
        return self._mascarar_placa(self.__placa)
    
    def _validar_ano(self, ano: int) -> int:
        """Valida o ano do veículo"""
        ano_atual = datetime.now().year
        if ano < 1900 or ano > ano_atual + 1:
            raise ValueError(f"Ano deve estar entre 1900 e {ano_atual + 1}")
        return ano
    
    def _validar_placa(self, placa: str) -> str:
        """Valida o formato da placa (formato antigo ou Mercosul)"""
        placa_limpa = re.sub(r'[^A-Z0-9]', '', placa.upper())
        
        # Formato antigo: AAA9999
        if re.match(r'^[A-Z]{3}[0-9]{4}$', placa_limpa):
            return placa_limpa
        
        # Formato Mercosul: AAA9A99
        if re.match(r'^[A-Z]{3}[0-9][A-Z][0-9]{2}$', placa_limpa):
            return placa_limpa
        
        raise ValueError("Formato de placa inválido")
    
    def _mascarar_placa(self, placa: str) -> str:
        """Mascara a placa para exibição"""
        if len(placa) == 7:
            return f"{placa[:3]}-{placa[3:]}"
        return placa
    
    def verificar_placa(self, placa_informada: str) -> bool:
        """Verifica se a placa informada corresponde à cadastrada"""
        try:
            placa_validada = self._validar_placa(placa_informada)
            return placa_validada == self.__placa
        except ValueError:
            return False
    
    def exibir_detalhes(self) -> None:
        """Exibe detalhes do carro de forma segura"""
        print(f"Veículo: {self.marca} {self.modelo}")
        print(f"Ano: {self.ano}")
        print(f"Cor: {self.cor}")
        print(f"Placa: {self.placa}")  # Placa mascarada


class Seguro:
    """Classe Seguro com métodos de validação encapsulados"""
    
    def __init__(self, cliente: Cliente, carro: Carro, valor: float, vigencia: date):
        self._cliente = cliente
        self._carro = carro
        self._valor = self._validar_valor(valor)
        self._vigencia = vigencia
        self._data_contratacao = datetime.now()
        self._ativo = True
    
    @property
    def cliente(self) -> Cliente:
        return self._cliente
    
    @property
    def carro(self) -> Carro:
        return self._carro
    
    @property
    def valor(self) -> float:
        return self._valor
    
    @property
    def vigencia(self) -> date:
        return self._vigencia
    
    @property
    def ativo(self) -> bool:
        return self._ativo
    
    def _validar_valor(self, valor: float) -> float:
        """Valida o valor do seguro"""
        if valor <= 0:
            raise ValueError("Valor do seguro deve ser positivo")
        if valor > 50000:
            raise ValueError("Valor do seguro excede o limite máximo")
        return valor
    
    def calcular_valor(self, base_valor: float, taxa: float) -> float:
        """Calcula o valor do seguro com validações"""
        if base_valor <= 0 or taxa < 0:
            raise ValueError("Parâmetros de cálculo inválidos")
        
        valor_calculado = base_valor * (1 + taxa)
        self._valor = self._validar_valor(valor_calculado)
        return self._valor
    
    def verificar_vigencia(self) -> bool:
        """
        Pseudocódigo para verificação de validade da apólice:
        
        INÍCIO verificar_vigencia()
            data_atual ← obter_data_atual()
            
            SE não self._ativo ENTÃO
                RETORNAR False
            FIM SE
            
            SE data_atual > self._vigencia ENTÃO
                self._ativo ← False
                RETORNAR False
            FIM SE
            
            // Verifica se está próximo do vencimento (30 dias)
            dias_para_vencer ← (self._vigencia - data_atual).dias
            SE dias_para_vencer <= 30 E dias_para_vencer > 0 ENTÃO
                emitir_alerta_renovacao()
            FIM SE
            
            RETORNAR True
        FIM verificar_vigencia()
        """
        data_atual = date.today()
        
        if not self._ativo:
            return False
        
        if data_atual > self._vigencia:
            self._ativo = False
            return False
        
        # Alerta de renovação
        dias_para_vencer = (self._vigencia - data_atual).days
        if 0 < dias_para_vencer <= 30:
            self._emitir_alerta_renovacao(dias_para_vencer)
        
        return True
    
    def _emitir_alerta_renovacao(self, dias: int) -> None:
        """Método privado para emitir alerta de renovação"""
        print(f"⚠️  ALERTA: Seguro vence em {dias} dias. Considere renovar!")
    
    def cancelar_seguro(self, motivo: str = "") -> bool:
        """Cancela o seguro de forma segura"""
        if not self._ativo:
            print("Seguro já está cancelado")
            return False
        
        self._ativo = False
        print(f"Seguro cancelado. Motivo: {motivo or 'Não informado'}")
        return True
    
    def exibir_informacoes_seguro(self) -> None:
        """Exibe informações do seguro de forma segura"""
        print("=== INFORMAÇÕES DO SEGURO ===")
        print(f"Cliente: {self.cliente.nome}")
        print(f"Veículo: {self.carro.marca} {self.carro.modelo}")
        print(f"Valor: R$ {self.valor:.2f}")
        print(f"Vigência: {self.vigencia.strftime('%d/%m/%Y')}")
        print(f"Status: {'Ativo' if self.ativo else 'Inativo'}")
        print(f"Válido: {'Sim' if self.verificar_vigencia() else 'Não'}")


# Demonstração da importância do encapsulamento
if __name__ == "__main__":
    print("=== DEMONSTRAÇÃO DE ENCAPSULAMENTO ===\n")
    
    try:
        # Criando objetos com dados sensíveis
        cliente = Cliente("João Silva", "12345678900")
        carro = Carro(2020, "toyota", "corolla", "branco", "XYZ1234")
        seguro = Seguro(cliente, carro, 1500.0, date(2025, 12, 31))
        
        print("1. ACESSO SEGURO ÀS INFORMAÇÕES:")
        cliente.exibir_informacoes()
        print()
        carro.exibir_detalhes()
        print()
        
        print("2. TENTATIVA DE ACESSO DIRETO (FALHARÁ):")
        try:
            # Isso causará erro - atributo privado
            print(f"CPF real: {cliente.__cpf}")
        except AttributeError as e:
            print(f"❌ Erro ao acessar CPF diretamente: {type(e).__name__}")
        
        try:
            # Isso também causará erro
            print(f"Placa real: {carro.__placa}")
        except AttributeError as e:
            print(f"❌ Erro ao acessar placa diretamente: {type(e).__name__}")
        
        print("\n3. VERIFICAÇÃO SEGURA DE DADOS:")
        print(f"CPF correto? {cliente.verificar_cpf('123.456.789-00')}")
        print(f"Placa correta? {carro.verificar_placa('XYZ-1234')}")
        
        print("\n4. VERIFICAÇÃO DE VIGÊNCIA:")
        seguro.exibir_informacoes_seguro()
        
        print("\n=== IMPORTÂNCIA DO ENCAPSULAMENTO ===")
        print("• Protege informações sensíveis (CPF, placa)")
        print("• Controla acesso através de métodos específicos")
        print("• Valida dados antes de armazená-los")
        print("• Permite alterações internas sem afetar código cliente")
        print("• Garante integridade dos dados")
        print("• Facilita manutenção e debugging")
        
    except Exception as e:
        print(f"Erro na demonstração: {e}")