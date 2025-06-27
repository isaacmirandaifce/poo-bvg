# excecoes.py

class ErroPersistencia(Exception):
    """Classe base para exceções de persistência."""
    pass

class ArquivoNaoEncontradoError(ErroPersistencia):
    """Exceção para quando o arquivo de dados não é encontrado."""
    # Exemplo de exceção personalizada [cite: 10]
    def __init__(self, arquivo):
        super().__init__(f"Erro: O arquivo '{arquivo}' não foi encontrado.")

class PermissaoNegadaError(ErroPersistencia):
    """Exceção para quando não há permissão para ler ou escrever no arquivo."""
    # Exemplo de exceção personalizada [cite: 10]
    def __init__(self, arquivo):
        super().__init__(f"Erro: Permissão negada para acessar o arquivo '{arquivo}'.")

class FalhaConversaoDadosError(ErroPersistencia):
    """Exceção para erros ao converter dados lidos do arquivo."""
    # Atende ao requisito de falhas na conversão de dados [cite: 8]
    def __init__(self, detalhes):
        super().__init__(f"Erro de conversão de dados: {detalhes}")