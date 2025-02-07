import signal
import sys
from models.persistencia import Persistencia

"""Trata os sinais"""
def tratarSinal(signal_received, frame):
    print("\n Sinal detectado! Salvando dados antes de encerrar...")
    dados_exemplo = [{"nome": "aluno exemplo", "matricula": "12345"}]
    Persistencia.salvar_dados("dados.txt", dados_exemplo)
    print("Dados salvos com sucesso! Encerrando o programa.")
    sys.exit(0)
  
signal.signal(signal.SIGINT, tratarSinal)  # CTRL+C
signal.signal(signal.SIGTERM, tratarSinal)  # Fechando o sistema
