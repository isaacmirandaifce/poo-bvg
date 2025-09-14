# src/sistema_academico.py
from . import persistencia
from .excecoes import ErroPersistencia
from .aluno import Aluno
from .professor import Professor

class SistemaAcademico:
    """Classe que gerencia os dados do sistema e a persistência."""
    
    _instancia = None

    def __new__(cls, *args, **kwargs):
        if not cls._instancia:
            cls._instancia = super(SistemaAcademico, cls).__new__(cls, *args, **kwargs)
        return cls._instancia

    def __init__(self):
        self.alunos = []
        self.professores = []

    def carregar_dados_iniciais(self):
        """Tenta carregar os dados dos arquivos ao iniciar."""
        print("Tentando carregar dados existentes...")
        try:
            self.alunos, self.professores = persistencia.carregar_dados()
            print(f"{len(self.alunos)} aluno(s) e {len(self.professores)} professor(es) carregados com sucesso.")
        except ErroPersistencia as e:
            print(f"AVISO: Não foi possível carregar os dados. Erro: {e}")
            print("Iniciando com listas vazias.")

    def salvar_todos_os_dados(self):
        """Salva o estado atual do sistema nos arquivos."""
        print("\nSalvando todos os dados...")
        try:
            persistencia.salvar_dados(self.alunos, self.professores)
            print("Dados salvos com sucesso!")
        except ErroPersistencia as e:
            print(f"ERRO CRÍTICO: Não foi possível salvar os dados. Erro: {e}")

    def adicionar_aluno(self, nome, id_usuario, senha, curso):
        """Adiciona um novo aluno e aciona o auto-save."""
        novo_aluno = Aluno(nome, id_usuario, senha, curso)
        self.alunos.append(novo_aluno)
        print(f"Aluno '{nome}' adicionado.")
        self.salvar_todos_os_dados() # Auto-save

    def adicionar_professor(self, nome, id_usuario, senha, departamento, disciplinas):
        """Adiciona um novo professor e aciona o auto-save."""
        novo_professor = Professor(nome, id_usuario, senha, departamento, disciplinas)
        self.professores.append(novo_professor)
        print(f"Professor '{nome}' adicionado.")
        self.salvar_todos_os_dados() # Auto-save