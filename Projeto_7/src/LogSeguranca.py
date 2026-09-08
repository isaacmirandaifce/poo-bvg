class LogSeguranca:
    def __init__(self, timestamp: str, nivel: str, mensagem: str):
        self.__timestamp = timestamp
        self.__nivel = nivel
        self.__mensagem = mensagem

    def get_nivel(self) -> str:
        return self.__nivel

    def __str__(self) -> str:
        return f"Log [{self.__timestamp}] {self.__nivel}: {self.__mensagem}"