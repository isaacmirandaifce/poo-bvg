from base.UsuarioAutenticavel import UsuarioAutenticavel
from interfaces.Relatorio import Relatorio
from models.TipoUsuario import TipoUsuario

class UsuarioOperador(UsuarioAutenticavel, Relatorio):
    class __HistoricoAcessos:
        def __init__(self):
            self.__registros = []

        def adicionar(self, recurso: str, data_hora: str, status_codigo: int):
            self.__registros.append({
                "recurso_acessado": recurso,
                "data_hora": data_hora,
                "status_codigo": status_codigo
            })

        def obter_todos(self):
            return self.__registros

    def __init__(self, user_id: int, username: str, senha: str):
        super().__init__(user_id, username, senha)
        self.__tipo = TipoUsuario.OPERADOR
        self.__historico = self.__HistoricoAcessos()

    def autenticar(self, senha: str) -> bool:
        return self._verificar_senha(senha)

    def simular_acesso(self, recurso: str, data_hora: str, status: int):
        self.__historico.adicionar(recurso, data_hora, status)

    def gerar_relatorio(self) -> None:
        print(f"\n[RELATÓRIO {self.__tipo.value}] - Operações de Caixa")
        print(f"Colaborador: {self.username}")
        print("Trilha de Auditoria (Acessos):")
        
        registros = self.__historico.obter_todos()
        if not registros:
            print(" - Nenhum acesso registrado.")
        else:
            for reg in registros:
                print(f" -> {reg['data_hora']} | {reg['recurso_acessado']} [Status: {reg['status_codigo']}]")