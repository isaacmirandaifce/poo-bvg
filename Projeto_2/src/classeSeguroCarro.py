#Importa a classe base SeguroVeiculo
from classeSeguroVeiculo import SeguroVeiculo

class SeguroCarro(SeguroVeiculo):
  """
  Representa um seguro só para carros
  Herda atributos da classe base SeguroVeiculo
  
  """
  def __init__(self, cliente, carro, valorBase, vigenciaInicio, vigenciaFim):
    """
    Inicializa um seguro pra um carro
    
    :param cliente: objeto Cliente associado a carro
    :param carro: objeto Carro a ser assegurado
    :param valorBase: valor base do seguro
    :param vigenciaInicio: data de inicio da vigencia do seguro
    :param vigenciaFim: data do fim da vigencia do seguro
    
    """
    
    #Inicia a classe base SeguroVeiculo
    super().__init__(cliente, valorBase, vigenciaInicio, vigenciaFim)
    
    #Atribui carro ao seguro
    self.carro = carro
    
  def calcularValor(self):
    """
    Calcula o valor do seguro baseado no ano do carro
    
    :return: valor ajustado do seguro
    
    """
    #Se o carro for mais antigo que 2020
    if self.carro.ano < 2020:
      return self.valorBase * 1.2
    
    #Se não, mantém o valor base
    return self.valorBase
  
  
    
