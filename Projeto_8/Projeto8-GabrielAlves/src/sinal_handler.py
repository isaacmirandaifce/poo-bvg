# sinal_handler.py

import signal
import sys
from persistencia import salvar_dados

def tratador_de_sinal(sinal, frame):
    """
    Função de tratamento que é chamada quando um sinal do SO é capturado.
    """
    print(f"\nSinal {signal.Signals(sinal).name} recebido.")
    
    # Tenta salvar os dados de forma segura antes de encerrar [cite: 12]
    try:
        salvar_dados()
    except Exception as e:
        print(f"Não foi possível salvar os dados antes de sair: {e}")

    # Imprime uma mensagem informando o motivo do encerramento [cite: 13]
    print("Encerrando o sistema de forma segura.")
    sys.exit(0)

def inicializar():
    """
    Configura os tratadores para os sinais SIGINT e SIGTERM.
    """
    # Captura SIGINT (Interrupção via Ctrl+C) [cite: 11]
    signal.signal(signal.SIGINT, tratador_de_sinal)
    
    # Captura SIGTERM (Finalização solicitada pelo SO) [cite: 11]
    signal.signal(signal.SIGTERM, tratador_de_sinal)
    
    # Nota: SIGSEGV (falha de segmentação) é mais difícil e muitas vezes
    # inseguro de tratar em Python, pois indica um erro grave,
    # possivelmente na própria CPython. A tentativa de salvar dados pode
    # levar a mais erros. Por isso, focamos nos sinais de encerramento. [cite: 11]

    print("[SINAL HANDLER] Manipuladores de sinal inicializados.")