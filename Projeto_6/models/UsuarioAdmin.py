from base.UsuarioAutenticavel import UsuarioAutenticavel
from interfaces.Relatorio import Relatorio
from models.TipoUsuario import TipoUsuario

class UsuarioAdmin(UsuarioAutenticavel, Relatorio):
    def __init__(self, user_id: int, username: str, senha: str):
        super().__init__(user_id, username, senha)
        self.__tipo = TipoUsuario.ADMIN
        self.__logs_sistema = []

    def autenticar(self, senha: str) -> bool:
        return self._verificar_senha(senha)

    def registrar_modificacao(self, log: str):
        self.__logs_sistema.append(log)

    def gerar_relatorio(self) -> None:
        print(f"\n[RELATÓRIO {self.__tipo.value}] - TI / Infraestrutura")
        print(f"Responsável: {self.username} (ID: {self.id})")
        print("Logs de Modificações:")
        for log in self.__logs_sistema:
            print(f" - {log}")