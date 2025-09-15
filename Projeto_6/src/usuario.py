class Usuario:
    def __init__(self, nome: str, login: str, tipo_usuario):
        self._nome = nome
        self._login = login
        self._tipo_usuario = tipo_usuario

    @property
    def nome(self):
        return self._nome

    @property
    def tipo_usuario(self):
        return self._tipo_usuario
