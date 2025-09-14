# src/excecoes.py

class ErroPersistencia(Exception):
    """Classe base para erros relacionados à persistência de dados."""
    pass

class ArquivoNaoEncontradoError(ErroPersistencia):
    """Exceção para quando um arquivo de dados não é encontrado."""
    def __init__(self, caminho_arquivo: str):
        super().__init__(f"O arquivo de dados não foi encontrado no caminho: {caminho_arquivo}")

class PermissaoNegadaError(ErroPersistencia):
    """Exceção para quando não há permissão para ler ou escrever um arquivo."""
    def __init__(self, caminho_arquivo: str):
        super().__init__(f"Permissão negada para acessar o arquivo: {caminho_arquivo}")

class ErroConversaoDadosError(ErroPersistencia):
    """Exceção para falhas ao converter dados lidos de um arquivo."""
    def __init__(self, linha: int, erro: str):
        super().__init__(f"Erro ao converter dados na linha {linha}: {erro}")