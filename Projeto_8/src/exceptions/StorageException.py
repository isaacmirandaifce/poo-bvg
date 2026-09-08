class StorageException(Exception):
    """Classe base para erros do subsistema de armazenamento."""
    def __init__(self, message: str):
        self.__message = message
        super().__init__(self.__message)

    def what(self) -> str:
        """Emula o comportamento do virtual const char* what() do C++."""
        return self.__message

class FileCorruptedException(StorageException):
    """Disparada quando o CSV contém linhas inválidas ou dados corrompidos."""
    def __init__(self, message: str = "Arquivo de ledger corrompido ou formato inválido."):
        super().__init__(message)

class DiskWriteException(StorageException):
    """Disparada quando ocorre falha no flush ou IO."""
    def __init__(self, message: str = "Falha de escrita no disco (permissão, IO ou espaço)."):
        super().__init__(message)