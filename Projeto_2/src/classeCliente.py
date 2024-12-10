#Crio a classe Cliente
class Cliente:
  def __init__(self, nome, cpf):
    self.nome = nome
    self.__cpf = cpf
  
  #Metodo público para acessar cpf
  def get_cpf(self):
    return self.__cpf    #Retorna o valor cpf
  
  #Metodo público para alterar cpf
  def set_cpf(self, novoCPF):
    self.__cpf = novoCPF    #Altera o valor cpf