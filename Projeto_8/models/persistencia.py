import os
from models.excecoes import PermissaoNegadaException
from models.aluno import Aluno  # Importa a classe para reconstrução

class Persistencia:
    """Classe para manipulação de persistência de dados"""

    @staticmethod
    def carregar_dados(nome_arquivo):
        """Carrega os dados do arquivo especificado"""
        if not os.path.exists(nome_arquivo):
            print(f"Arquivo '{nome_arquivo}' não encontrado! Criando um novo...")
            with open(nome_arquivo, "w", encoding="utf-8") as arquivo:
                arquivo.write('')
            return []  # Retorna lista vazia para evitar erro
        
        try:
            with open(nome_arquivo, "r", encoding="utf-8") as arquivo:
                linhas = arquivo.readlines()
                dados = [eval(linha.strip()) for linha in linhas if linha.strip()]  # Avaliar cada linha como dicionário
                return dados  # Retornar os dados diretamente como dicionários
        except PermissionError:
            raise PermissaoNegadaException(nome_arquivo)
        except Exception as e:
            print(f"Erro ao carregar dados: {e}")
            return []

    @staticmethod
    def salvar_dados(nome_arquivo, dados):
        """Salva os dados no arquivo especificado"""
        try:
            dados_serializaveis = [aluno.to_dict() for aluno in dados]

            with open(nome_arquivo, "w", encoding="utf-8") as arquivo:
                for dado in dados_serializaveis:
                    arquivo.write(str(dado) + '\n')
        except PermissionError:
            raise PermissaoNegadaException(nome_arquivo)
