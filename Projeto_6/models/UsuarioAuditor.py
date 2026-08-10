from base.UsuarioAutenticavel import UsuarioAutenticavel
from interfaces.Relatorio import Relatorio
from models.TipoUsuario import TipoUsuario

class UsuarioAuditor(UsuarioAutenticavel, Relatorio):
    def __init__(self, user_id: int, username: str, senha: str):
        super().__init__(user_id, username, senha)
        self.__tipo = TipoUsuario.AUDITOR
        self.__chaves_publicas = ["0xABC123", "0xDEF456"]
        self.__escopo_varredura = "Contas Correntes e Transações PIX"

    def autenticar(self, senha: str) -> bool:
        return self._verificar_senha(senha)

    def gerar_relatorio(self) -> None:
        print(f"\n[RELATÓRIO {self.__tipo.value}] - Prevenção a Fraudes")
        print(f"Responsável: {self.username}")
        print(f"Escopo: {self.__escopo_varredura}")
        print(f"Chaves de Criptografia Auditadas: {', '.join(self.__chaves_publicas)}")