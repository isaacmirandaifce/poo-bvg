from models.SensorGPS import SensorGPS
from models.SensorDiagnostico import SensorDiagnostico
from models.RastreadorAvancado import RastreadorAvancado

def main():
    frota = [
        SensorGPS("IFCE-BV-GPS01", 16790010, -3.7318, -38.5266),
        SensorDiagnostico("IFCE-BV-OBD01", 16790011, 3500, 95.5),
        RastreadorAvancado("IFCE-BV-ADV01", 16790012, -3.7450, -38.5120, 2800, 89.0)
    ]

    print("=== INICIANDO PROCESSAMENTO DE TELEMETRIA ===")
    for i, dispositivo in enumerate(frota, 1):
        print(f"\n--- Dispositivo {i} ---")
        dispositivo.processarDados()

    print("\n=== TESTANDO SOBRECARGA DE METODOS (GPS) ===")
    gps_device = frota[0]
    gps_device.transmitirPayload()                  
    gps_device.transmitirPayload("AES256-Key-X9")   

    print("\n=== LIMPANDO MEMORIA ===")
    frota.clear()
    print("LOG: Referências removidas. O Garbage Collector cuidará da liberação de memória.")

if __name__ == "__main__":
    main()