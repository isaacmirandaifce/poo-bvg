# src/persistencia.py
import csv
from .aluno import Aluno
from .professor import Professor
from .excecoes import ArquivoNaoEncontradoError, PermissaoNegadaError, ErroConversaoDadosError

# Define os caminhos dos arquivos de dados
CAMINHO_ALUNOS = "dados/alunos.csv"
CAMINHO_PROFESSORES = "dados/professores.csv"

def salvar_dados(alunos: list, professores: list):
    """Salva as listas de alunos e professores em arquivos CSV."""
    try:
        # Salvar alunos
        with open(CAMINHO_ALUNOS, 'w', newline='', encoding='utf-8') as f:
            writer = csv.writer(f)
            writer.writerow(["nome", "id_usuario", "senha", "curso", "historico"])
            for aluno in alunos:
                # Serializa o histórico para uma string. Ex: "POO:2024:9.5;BD:2024:8.0"
                historico_str = ";".join([f"{h.nome_disciplina}:{h.ano_cursado}:{h.nota}" for h in aluno.historico])
                writer.writerow([aluno.nome, aluno.id_usuario, aluno._senha, aluno._curso, historico_str])

        # Salvar professores
        with open(CAMINHO_PROFESSORES, 'w', newline='', encoding='utf-8') as f:
            writer = csv.writer(f)
            writer.writerow(["nome", "id_usuario", "senha", "departamento", "disciplinas"])
            for prof in professores:
                disciplinas_str = ";".join(prof.disciplinas_ministradas)
                writer.writerow([prof.nome, prof.id_usuario, prof._senha, prof._departamento, disciplinas_str])
                
    except PermissionError as e:
        raise PermissaoNegadaError(e.filename) from e

def carregar_dados() -> tuple[list[Aluno], list[Professor]]:
    """Carrega os dados de alunos e professores a partir de arquivos CSV."""
    alunos, professores = [], []
    try:
        # Carregar alunos
        with open(CAMINHO_ALUNOS, 'r', encoding='utf-8') as f:
            reader = csv.reader(f)
            next(reader) # Pula o cabeçalho
            for i, row in enumerate(reader):
                try:
                    aluno = Aluno(nome=row[0], id_usuario=int(row[1]), senha=row[2], curso=row[3])
                    if row[4]: # Se houver histórico
                        for item in row[4].split(';'):
                            nome_disc, ano, nota = item.split(':')
                            aluno.adicionar_disciplina_historico(nome_disc, int(ano), float(nota))
                    alunos.append(aluno)
                except (ValueError, IndexError) as e:
                    raise ErroConversaoDadosError(linha=i + 2, erro=str(e))

        # Carregar professores
        with open(CAMINHO_PROFESSORES, 'r', encoding='utf-8') as f:
            reader = csv.reader(f)
            next(reader) # Pula o cabeçalho
            for i, row in enumerate(reader):
                try:
                    disciplinas = row[4].split(';') if row[4] else []
                    prof = Professor(nome=row[0], id_usuario=int(row[1]), senha=row[2], departamento=row[3], disciplinas_ministradas=disciplinas)
                    professores.append(prof)
                except (ValueError, IndexError) as e:
                    raise ErroConversaoDadosError(linha=i + 2, erro=str(e))
        
        return alunos, professores
        
    except FileNotFoundError:
       
        return [], []
    except PermissionError as e:
        raise PermissaoNegadaError(e.filename) from e