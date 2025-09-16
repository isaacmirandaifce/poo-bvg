import signal 
import sys
from persistencia import salvar_dados_csv

def tratador_sinal(sig, frame):
    print("\nSinal de interrupção recebido. Salvando dados e encerrando o programa...")
    # Exemplo de dados a serem salvos
    dados = [
        {"id": 1, "nome": "Exemplo1"},
        {"id": 2, "nome": "Exemplo2"}
    ]
    campos = ["id", "nome"]
    salvar_dados_csv("dados_salvos.csv", dados, campos)
    print("Dados salvos com sucesso. Encerrando o programa.")
    sys.exit(0)

def registrar_sinais():
    signal.signal(signal.SIGINT, tratador_sinal)
    signal.signal(signal.SIGTERM, tratador_sinal)