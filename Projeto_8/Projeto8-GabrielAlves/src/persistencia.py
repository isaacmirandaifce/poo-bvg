# persistencia.py

import csv
from modelos import Aluno, Professor, Disciplina
from excecoes import ArquivoNaoEncontradoError, PermissaoNegadaError, FalhaConversaoDadosError

# Dicionário global para manter o estado dos dados em memória.
# Isso permite que o manipulador de sinal acesse os dados mais recentes.
dados_em_memoria = {
    "alunos": [],
    "professores": [],
    "disciplinas": []
}

def salvar_dados():
    """
    Salva todas as listas de dados (alunos, professores, disciplinas)
    em seus respectivos arquivos CSV.
    """
    print("\n[PERSISTÊNCIA] Tentando salvar dados...")
    try:
        # Salva Alunos
        with open('alunos.csv', 'w', newline='', encoding='utf-8') as f:
            writer = csv.writer(f)
            writer.writerow(['id', 'nome'])
            for aluno in dados_em_memoria["alunos"]:
                writer.writerow([aluno.id, aluno.nome])

        # Salva Professores
        with open('professores.csv', 'w', newline='', encoding='utf-8') as f:
            writer = csv.writer(f)
            writer.writerow(['id', 'nome'])
            for professor in dados_em_memoria["professores"]:
                writer.writerow([professor.id, professor.nome])

        # Salva Disciplinas
        with open('disciplinas.csv', 'w', newline='', encoding='utf-8') as f:
            writer = csv.writer(f)
            writer.writerow(['id', 'nome'])
            for disciplina in dados_em_memoria["disciplinas"]:
                writer.writerow([disciplina.id, disciplina.nome])
        
        print("[PERSISTÊNCIA] Dados salvos com sucesso!")

    except PermissionError:
        # Trata erro de permissão negada ao gravar o arquivo [cite: 8]
        raise PermissaoNegadaError("alunos.csv, professores.csv ou disciplinas.csv")
    except Exception as e:
        print(f"Ocorreu um erro inesperado ao salvar os dados: {e}")

def carregar_dados():
    """
    Carrega os dados dos arquivos CSV para as listas em memória.
    Realiza o tratamento de exceções para arquivos não encontrados,
    permissões e erros de conversão de dados. 
    """
    print("[PERSISTÊNCIA] Carregando dados iniciais...")
    try:
        # Carrega Alunos
        with open('alunos.csv', 'r', encoding='utf-8') as f:
            reader = csv.reader(f)
            next(reader) # Pula o cabeçalho
            for linha in reader:
                if len(linha) != 2:
                    raise FalhaConversaoDadosError("Linha de aluno com formato inválido.") # [cite: 8]
                dados_em_memoria["alunos"].append(Aluno(int(linha[0]), linha[1]))

        # Carrega Professores
        with open('professores.csv', 'r', encoding='utf-8') as f:
            reader = csv.reader(f)
            next(reader) # Pula o cabeçalho
            for linha in reader:
                dados_em_memoria["professores"].append(Professor(int(linha[0]), linha[1]))

        # Carrega Disciplinas
        with open('disciplinas.csv', 'r', encoding='utf-8') as f:
            reader = csv.reader(f)
            next(reader) # Pula o cabeçalho
            for linha in reader:
                dados_em_memoria["disciplinas"].append(Disciplina(int(linha[0]), linha[1]))
        
        print("[PERSISTÊNCIA] Dados carregados com sucesso.")

    except FileNotFoundError as e:
        # Trata erro de arquivo não encontrado [cite: 8]
        print(f"[AVISO] Arquivo '{e.filename}' não encontrado. Iniciando com listas vazias.")
    except PermissionError as e:
        # Trata erro de permissão negada ao abrir o arquivo [cite: 8]
        raise PermissaoNegadaError(e.filename)
    except (ValueError, IndexError) as e:
        # Trata falhas na conversão de dados [cite: 8]
        raise FalhaConversaoDadosError(f"Não foi possível converter um valor no arquivo. Detalhes: {e}")
    except Exception as e:
        print(f"Ocorreu um erro inesperado ao carregar os dados: {e}")