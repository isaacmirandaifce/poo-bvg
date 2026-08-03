from models.SensorGPS import SensorGPS
from models.SensorDiagnostico import SensorDiagnostico

class RastreadorAvancado(SensorGPS, SensorDiagnostico):
    def __init__(self, id_dispositivo: str, timestamp: int, latitude: float, longitude: float, rpm_motor: int, temperatura_fluido: float):
        SensorGPS.__init__(self, id_dispositivo, timestamp, latitude, longitude)
        SensorDiagnostico.__init__(self, id_dispositivo, timestamp, rpm_motor, temperatura_fluido)

    def processarDados(self) -> None:
        print(f"[FUSÃO AVANÇADA] Processando dados consolidados de {self._idDispositivo}:")
        SensorGPS.processarDados(self)
        SensorDiagnostico.processarDados(self)