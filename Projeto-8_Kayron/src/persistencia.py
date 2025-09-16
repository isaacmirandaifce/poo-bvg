import csv
from .excessao import ArquivoNaoEncontrado, PermissaoNegada, FalhaConversaoDeDados

def carregar_dados_csv(caminho_arquivo):
    try:
        with open(caminho_arquivo, mode='r', encoding='utf-8') as arquivo:
            leitor_csv = csv.DictReader(arquivo)
            dados = [linha for linha in leitor_csv]
            return dados
    except FileNotFoundError:
        raise ArquivoNaoEncontrado(f"O arquivo {caminho_arquivo} não foi encontrado.")
    except PermissionError:
        raise PermissaoNegada(f"Permissão negada para acessar o arquivo {caminho_arquivo}.")
    except csv.Error as e:
        raise FalhaConversaoDeDados(f"Falha na conversão dos dados do arquivo {caminho_arquivo}: {e}")
    
def salvar_dados_csv(caminho_arquivo, dados, campos):
    try:
        with open(caminho_arquivo, mode='w', encoding='utf-8', newline='') as arquivo:
            escritor_csv = csv.DictWriter(arquivo, fieldnames=campos)
            escritor_csv.writeheader()
            escritor_csv.writerows(dados)
    except PermissionError:
        raise PermissaoNegada(f"Permissão negada para escrever no arquivo {caminho_arquivo}.")
    except csv.Error as e:
        raise FalhaConversaoDeDados(f"Falha na conversão dos dados para o arquivo {caminho_arquivo}: {e}")

