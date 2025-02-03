# Define a classe Aluno
class Aluno:
    
    # Classe interna para representar o histórico disciplinar do aluno
    class HistoricoDisciplinar:
        
        # Método construtor da classe HistoricoDisciplinar
        def __init__(self):
            # Inicializa uma lista vazia para armazenar as disciplinas
            self.disciplinas = []  

        # Método para adicionar uma disciplina ao histórico
        def adicionar_disciplina(self, nome, ano, nota):
            # Adiciona um dicionário com informações da disciplina à lista de disciplinas
            self.disciplinas.append({"nome": nome, "ano": ano, "nota": nota})

        # Método para listar todas as disciplinas do histórico
        def listar_disciplinas(self):
            # Retorna a lista de disciplinas
            return self.disciplinas

    # Método construtor da classe Aluno
    def __init__(self, nome, email, senha, matricula, curso):
        
        # Importa a classe UsuarioAutenticavel do módulo models.autenticavel
        from models.autenticavel import UsuarioAutenticavel

        # Cria uma instância de UsuarioAutenticavel com os dados do aluno
        self.usuario_autenticavel = UsuarioAutenticavel(nome, email, senha)
        
        # Atribui a matrícula do aluno
        self.matricula = matricula
        
        # Atribui o curso do aluno
        self.curso = curso
        
        # Cria uma instância de HistoricoDisciplinar para o aluno
        self.historico = Aluno.HistoricoDisciplinar()
        
