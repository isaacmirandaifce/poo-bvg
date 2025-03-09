from src.models.UsuarioAutenticavel import UsuarioAutenticavel
from src.models.Relatorio import Relatorio
from src.models.TipoUsuario import TipoUsuario


class Professor(UsuarioAutenticavel, Relatorio):
    """
    Classe Professor que herda de UsuarioAutenticavel e implementa a interface Relatorio.
    Representa um professor com área de atuação e disciplinas ministradas.
    """

    def __init__(self, nome='indefinido', email='indefinido', tipo=TipoUsuario.PROFESSOR, senha='indefinido', areaDeAtuacao='indefinida', disciplinasMinistradas=None):
        """
        Inicializa os atributos do professor.

        Args:
            nome (str): Nome do professor.
            email (str): Email do professor.
            tipo (str): Tipo de usuário, por padrão 'Professor'.
            senha (str): Senha do professor para autenticação.
            areaDeAtuacao (str): Área de atuação do professor.
            disciplinasMinistradas (list[str]): Lista de disciplinas ministradas pelo professor.
        """
        super().__init__(nome, email, tipo, senha)
        self._areaDeAtuacao = areaDeAtuacao
        self._disciplinasMinistradas = disciplinasMinistradas or []

    def gerarRelatorio(self):
        """
        Gera um relatório com as informações do professor.

        Returns:
            str: Relatório formatado contendo nome, área de atuação e disciplinas ministradas.
        """
        disciplinas = ", ".join(self._disciplinasMinistradas)
        return (
            f"Nome: {self._nome}\n"
            f"Área de Atuação: {self._areaDeAtuacao}\n"
            f"Disciplinas Ministradas: {disciplinas if disciplinas else 'Nenhuma disciplina cadastrada'}"
        )

    def autenticar(self, senha):
        """
        Realiza a autenticação do professor com base na senha.

        Args:
            senha (str): Senha a ser verificada.

        Returns:
            bool: True se a senha estiver correta, False caso contrário.
        """
        return self._senha == senha
