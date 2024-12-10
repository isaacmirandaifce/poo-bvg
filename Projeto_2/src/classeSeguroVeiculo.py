#Define a classe base SeguroVeiculo
class SeguroVeiculo:
  """
  
   Representa um seguro genérico para veículos, armazenando 
   informações sobre o cliente, o valor base e o período de vigência.
  
  """
  def __init__(self, cliente, valorBase, vigenciaInicio, vigenciaFim):
    """
    Inicializa um seguro pra uma moto
    
    :param cliente: Objeto cliente associado à moto
    :param moto: Objeto moto a ser assegurada
    :param valorBase: Valor base do seguro
    :param vigenciaInicio: Data de inicio da vigencia do seguro
    :param vigenciaFim: Data do fim da vigencia do seguro
    
    """
    self.cliente = cliente    #Cliente associado ao seguro
    self.valorBase = valorBase    #Valor base do seguro
    self.vigenciaInicio = vigenciaInicio    #Data de inicio do seguro
    self.vigenciaFim = vigenciaFim    #Data do fim do seguro
    
  def calcularValor(self):
    """ 
    Calula o valor base do seguro
    :return: retorna o valor base do seguro
    
    """
    return self.valorBase
  
  def verificarValidade(self, dataAtual):
    """ 
    Verifica se o seguro ainda é válido
    
    :param dataAtual: Data a ser verificada
    :return: "Seguro válido" se estiver dentro do periodo de vigência,
             "Seguro expirado" caso contrário
    """
    
    #Verifica se a data atual ainda está em vigência
    if self.vigenciaInicio <= dataAtual <= self.vigenciaFim:
        return "Seguro válido"
    else:
        return "Seguro expirado"