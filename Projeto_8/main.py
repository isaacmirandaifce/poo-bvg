import time
from src.infrastructure.SignalHandler import SignalHandler
from src.infrastructure.LedgerPersistence import LedgerPersistence
from src.exceptions.StorageException import StorageException

def main():
    SignalHandler.inicializar()

    try:
        db = LedgerPersistence()
        historico = db.carregarDados()
        print(f"[ENGINE] Base de dados verificada. {len(historico)} registros carregados.")
        
        novas_transacoes = ["TX_1001;250.00;PIX", "TX_1002;12000.00;TED"]
        db.salvarDados(novas_transacoes)
        print("[ENGINE] Novas transações salvas e validadas no disco com sucesso.")

        print("[ENGINE] Sistema operacional rodando e aguardando interceptações...")
        print("[!] Pressione Ctrl+C (SIGINT) no terminal para disparar o OS Hook.")
        while True:
            time.sleep(1)

    except StorageException as e:
        print(f"[CRITICAL ERROR] Falha na camada de armazenamento: {e.what()}")
    except Exception as e:
        print(f"[UNKNOWN ERROR] Erro genérico de runtime: {str(e)}")

if __name__ == "__main__":
    main()