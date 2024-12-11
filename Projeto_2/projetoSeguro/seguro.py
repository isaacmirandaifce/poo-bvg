class Carro():
    def __init__(self, ano, modelo, marca, cor, placa):
        self.ano = ano
        self.modelo = modelo
        self.marca = marca
        self.cor = cor 
        self._placa = placa
    
    def exibir_detalhes(self):
        return f"Ano: {self.ano} Modelo: {self.modelo} Marca: {self.marca} Cor: {self.cor} Placa: {self._placa}"
    
    def atualizar_cor(self, nova_cor):
        self.cor = nova_cor
        
    def get_placa(self):
        return self._placa
        
class Cliente():
    def __init__(self, nome, cpf):
        self.nome = nome
        self._cpf = cpf
        
    def exibir_informacoes(self):
        return f"Nome: {self.nome} CPF: {self._cpf}"
    
    def get_cpf(self):
        return self._cpf 

class Seguro():
    def __init__(self, carro, cliente, valor, vigencia):
        self.carro = carro
        self.cliente = cliente 
        self.valor = valor 
        self.vigencia = vigencia 
    
    def calcular_valor(self, base_valor, taxa):
        self.valor = base_valor + (base_valor * taxa)
        return self.valor
    
    def verificar_vigencia(self):
        from datetime import datetime
        hoje = datetime.now().date()
        
        if hoje < datetime.now().date():
            return "Não iniciado"
        elif hoje<= self.vigencia:
            return "Válido"
        else:
            return "Expirado"
    
     

class seguroCarro(Seguro):
    def calcular_valor(self, base_valor, taxa):
        return super().calcular_valor(base_valor, taxa) + 200

class seguroMoto(Seguro):
    def calcular_valor(self, base_valor, taxa):
        return super().calcular_valor(base_valor, taxa) + 100
    
    
        