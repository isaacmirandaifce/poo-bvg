from models.Dispositivo import Dispositivo

class SensorGPS(Dispositivo):
    def __init__(self, id_dispositivo: str, timestamp: int, latitude: float, longitude: float):
        Dispositivo.__init__(self, id_dispositivo, timestamp)
        self.__latitude = latitude    
        self.__longitude = longitude  

    def processarDados(self) -> None:
        print(f"[ RODANDO... ] GPS Processando {self._idDispositivo} | Lat: {self.__latitude}, Lon: {self.__longitude}")

    def transmitirPayload(self, chave_cripto: str = None) -> None:
        if chave_cripto is None:
            print(" -> Enviando payload em texto puro (Inseguro).")
        else:
            print(f" -> Enviando payload criptografado com chave [{chave_cripto}].")