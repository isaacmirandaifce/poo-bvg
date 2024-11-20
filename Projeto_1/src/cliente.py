#É criada a classe Cliente

class Cliente:

#É iniciado um construtor com __init__ para criação de um novo cliente
#Ele recebe os parametros: nome, idade e saldo
#   
  def __init__(self,nome:str, idade:int, saldo:float):
    self.__nome = nome
    self.__idade = idade
    self.__saldo = saldo

#É criado o metodo mostrar_informações que printa as informações do cliente.

  def mostrar_informacoes(self):
    print(f"Cliente: {self.__nome}, Idade: {self.__idade}, Saldo: R${self.__saldo:.2f}")

#É criado o metodo atualizar_saldo que adiciona um valor ao saldo do cliente.
  def atualizar_saldo(self, valor: float):
    self.__saldo += valor


  
