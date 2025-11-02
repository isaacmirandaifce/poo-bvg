class Modelo:
    
    """Representa o modelo de um carro (atributo 'modelo' do carro)."""
    
    def __init__(self, nome: str):
        self.__nome = nome

    @property
    
    def nome(self):
        
        return self.__nome

    def __str__(self):
        
        return self.__nome