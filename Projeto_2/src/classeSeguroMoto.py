#Importa a classe base SeguroVeiculo
from classeSeguroVeiculo import SeguroVeiculo

class SeguroMoto(SeguroVeiculo):
  """
  Representa um seguro só para motos
  Herda os atributos da classa base SeguroVeiculo
  
  """
  
  def __init__(self, cliente, moto, valorBase, vigenciaInicio, vigenciaFim):
    """
    Inicializa um seguro pra uma moto
    
    :param cliente: Objeto cliente associado à moto
    :param moto: Objeto moto a ser assegurada
    :param valorBase: Valor base do seguro
    :param vigenciaInicio: Data de inicio da vigencia do seguro
    :param vigenciaFim: Data do fim da vigencia do seguro
    
    """
    
    #Inicia a classe base SeguroVeiculo
    super().__init__(cliente, valorBase, vigenciaInicio, vigenciaFim)
    
    #Atribui moto ao seguro
    self.moto = moto
      
  def calcularValor(self):
    """
    Calcula o valor do seguro baseado no ano do carro
    
    :return: valor ajustado do seguro
    
    """
    #Se o carro for mais antigo que 2020
    if self.moto.ano < 2020:
      return self.valorBase * 1.5
    
    #Se nao, mantém o valor base
    return self.valorBase