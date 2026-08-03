from models.Dispositivo import Dispositivo

class SensorDiagnostico(Dispositivo):
    def __init__(self, id_dispositivo: str, timestamp: int, rpm_motor: int, temperatura_fluido: float):
        Dispositivo.__init__(self, id_dispositivo, timestamp)
        self.__rpmMotor = rpm_motor                  
        self.__temperaturaFluido = temperatura_fluido  

    def processarDados(self) -> None:
        print(f"[ RODANDO... ] Processando {self._idDispositivo} | RPM: {self.__rpmMotor} | Temp: {self.__temperaturaFluido}C")