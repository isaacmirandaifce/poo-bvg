import serial
import time
from config.settings import ARDUINO_PORT, BAUD_RATE

def conectar_arduino():
    try:
        arduino = serial.Serial(ARDUINO_PORT, BAUD_RATE, timeout=1)
        time.sleep(2)
        return arduino
    except Exception as e:
        print(f"Erro ao conectar ao Arduino: {e}")
        return None

arduino = conectar_arduino()

def acionar_sirene():
    if arduino:
        arduino.write(b'1')
        return True
    return False