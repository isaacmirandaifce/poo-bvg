# src/sinal_handler.py
import signal
import sys
from .sistema_academico import SistemaAcademico

class SinalHandler:
    """Configura os tratadores de sinais para garantir o salvamento dos dados."""

    @staticmethod
    def inicializar():
        """Registra os tratadores para os sinais de interrupção."""
        signal.signal(signal.SIGINT, SinalHandler.tratador_saida_graciosa)
        signal.signal(signal.SIGTERM, SinalHandler.tratador_saida_graciosa)
        
        # ATENÇÃO: Tratar SIGSEGV é perigoso em Python. O estado pode estar
        # corrompido. Esta é uma implementação para fins didáticos.
        # Em produção, o ideal é deixar o programa falhar e analisar o core dump.
        # Este handler pode não funcionar em todas as plataformas (ex: Windows).
        if hasattr(signal, 'SIGSEGV'):
            signal.signal(signal.SIGSEGV, SinalHandler.tratador_falha_grave)

    @staticmethod
    def tratador_saida_graciosa(sinal, frame):
        """Salva os dados e encerra o programa de forma segura."""
        print(f"\nSinal {signal} recebido. Tentando salvar dados antes de sair...")
        sistema = SistemaAcademico() # Obtém a instância singleton
        sistema.salvar_todos_os_dados()
        print("Encerrando o programa.")
        sys.exit(0)

    @staticmethod
    def tratador_falha_grave(sinal, frame):
        """Tenta salvar os dados em caso de falha de segmentação."""
        print(f"\nFALHA GRAVE (Sinal {signal}) DETECTADA!")
        print("O estado do programa pode estar corrompido.")
        print("Tentando um último salvamento de emergência...")
        sistema = SistemaAcademico() # Obtém a instância singleton
        sistema.salvar_todos_os_dados()
        print("Salvamento de emergência concluído. O programa será encerrado.")
        sys.exit(1)