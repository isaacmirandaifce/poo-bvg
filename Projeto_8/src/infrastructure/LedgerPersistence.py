import os
from src.exceptions.StorageException import FileCorruptedException, DiskWriteException

class LedgerPersistence:
    def __init__(self, caminho_arquivo: str = "ledger.csv"):
        self.__caminho_arquivo = caminho_arquivo

    def salvarDados(self, transacoes: list[str]) -> None:
        try:
            with open(self.__caminho_arquivo, 'w', encoding='utf-8') as f:
                for t in transacoes:
                    f.write(t + '\n') 
                f.flush()
                os.fsync(f.fileno())
        except IOError as e:
            raise DiskWriteException(f"Erro ao salvar no arquivo {self.__caminho_arquivo}: {str(e)}")

    def carregarDados(self) -> list[str]:
        transacoes = []
        try:
            if not os.path.exists(self.__caminho_arquivo):
                return transacoes 
                
            with open(self.__caminho_arquivo, 'r', encoding='utf-8') as f:
                for index, linha in enumerate(f):
                    linha_limpa = linha.strip()
                    if not linha_limpa:
                        raise FileCorruptedException(f"Linha {index+1} vazia inesperada. Arquivo inconsistente.")
                    transacoes.append(linha_limpa)
                    
        except IOError as e:
            raise FileCorruptedException(f"Falha crônica ao ler o arquivo {self.__caminho_arquivo}: {str(e)}")
            
        return transacoes