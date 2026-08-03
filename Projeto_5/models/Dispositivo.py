from abc import ABC, abstractmethod

class Dispositivo(ABC):
    def __init__(self, id_dispositivo: str, timestamp: int):
        self._idDispositivo = id_dispositivo 
        self._timestamp = timestamp           

    @abstractmethod
    def processarDados(self) -> None:
        """Método Virtual Puro"""
        pass