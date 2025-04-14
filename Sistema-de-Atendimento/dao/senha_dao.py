import json
import os

class SenhaDAO:
    def __init__(self, caminho='dados/senhas.json'):
        self._caminho = caminho
        self._inicializar_arquivo()

    def _inicializar_arquivo(self):
        try:
            if not os.path.exists(self._caminho):
                with open(self._caminho, 'w') as f:
                    json.dump({'emitidas': [], 'atendidas': []}, f)
        except Exception as e:
            raise Exception(f"Erro ao inicializar o arquivo de senhas: {e}")

    def carregar_dados(self):
        try:
            with open(self._caminho, 'r') as f:
                return json.load(f)
        except Exception as e:
            raise Exception(f"Erro ao carregar dados do arquivo: {e}")

    def salvar_dados(self, dados):
        try:
            with open(self._caminho, 'w') as f:
                json.dump(dados, f, indent=4)
        except Exception as e:
            raise Exception(f"Erro ao salvar dados no arquivo: {e}")
