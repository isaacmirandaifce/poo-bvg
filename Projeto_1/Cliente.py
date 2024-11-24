class Cliente():
  def __init__(self, nome, idade, saldo):
    self._nome = nome
    self._idade = idade
    self._saldo = saldo


  def __str__(self):
      return f'nome:{self._nome}, idade:{self._idade}, saldo:{self._saldo}'

  def atualizar_saldo(self, novo_valor):
      self._saldo = novo_valor

