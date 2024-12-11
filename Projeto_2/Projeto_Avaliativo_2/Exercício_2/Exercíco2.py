from datetime import datetime, timedelta

class Carro:
    def __init__(self, ano, marca, modelo, cor, placa):
        self.ano = ano
        self.marca = marca
        self.modelo = modelo
        self.cor = cor
        self.placa = placa

    def exibir_detalhes(self):
        """Exibe as informações do carro."""
        print(f"Carro: {self.marca} {self.modelo} ({self.ano}), Cor: {self.cor}, Placa: {self.placa}")

    def atualizar_cor(self, nova_cor):
        """Modifica a cor do carro."""
        self.cor = nova_cor
        print(f"A cor do carro foi atualizada para {self.cor}.")

class Cliente:
    def __init__(self, nome, cpf):
        self.nome = nome
        self.cpf = cpf

    def exibir_informacoes(self):
        """Exibe o nome e o CPF do cliente."""
        print(f"Cliente: {self.nome}, CPF: {self.cpf}")

class Seguro:
    def __init__(self, carro, cliente, valor, vigencia):
        self.carro = carro
        self.cliente = cliente
        self.valor = valor
        self.vigencia = vigencia  

    def calcular_valor(self, base_valor, taxa):
        """Calcula o valor do seguro com base em um valor base e uma taxa."""
        self.valor = base_valor + (base_valor * taxa)
        return self.valor

    def verificar_vigencia(self):
        """Verifica se o seguro ainda está válido."""
        hoje = datetime.today()
        if self.vigencia > hoje:
            print("O seguro está válido.")
            return True
        else:
            print("O seguro acabou.")
            return False

if __name__ == "__main__":
    carro = Carro(2020, "Volkswagen", "Fusca", "Azul", "ABC-1234")
    carro.exibir_detalhes()

    carro.atualizar_cor("Verde")

    cliente = Cliente("João Silva", "123.456.789-00")
    cliente.exibir_informacoes()

    vigencia = datetime.today() + timedelta(days=365) 
    seguro = Seguro(carro, cliente, 0, vigencia)

    base_valor = 1000.0  
    taxa = 0.1  
    valor_seguro = seguro.calcular_valor(base_valor, taxa)
    print(f"Valor do seguro: R${valor_seguro:.2f}")

    seguro.verificar_vigencia()
