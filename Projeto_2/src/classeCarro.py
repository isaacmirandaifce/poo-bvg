class Carro:
  #Metodo construtor
  def __init__(self, marca, modelo, ano, cor, placa):
    self.marca = marca
    self.modelo = modelo
    self.ano = ano
    self.cor = cor
    self.__placa = placa    #Atributo privado 'placa'
  
  #Metodo público para acessar placa  
  def get_placa(self):
    return self.__placa    #Retorna placa
  
  #Metodo público para alterar placa
  def set_placa(self, novaPlaca):
    self.__placa = novaPlaca    #Altera placa