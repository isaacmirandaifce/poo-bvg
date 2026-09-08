import signal
import sys

class SignalHandler:
    @staticmethod
    def inicializar() -> None:
        """Registra os hooks do Sistema Operacional."""
        signal.signal(signal.SIGINT, SignalHandler.__tratador)
        signal.signal(signal.SIGTERM, SignalHandler.__tratador)

    @staticmethod
    def __tratador(sinal: int, frame) -> None:
        """Método estático e privado invocado pelo SO durante uma interrupção."""
        print(f"\n[CRITICAL WARNING] Sinal do SO interceptado (ID: {sinal}).")
        print("[LOG EMERGÊNCIAL] Fechando arquivos e executando flush de buffers...")
        
        # Simula o encerramento seguro
        print("[ENGINE] Sistema encerrado de forma limpa. Nenhum dado corrompido.")
        sys.exit(sinal)