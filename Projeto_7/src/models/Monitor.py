from src.models.Aluno import Aluno
from src.models.Professor import Professor
from src.models.TipoUsuario import TipoUsuario

class Monitor(Aluno, Professor):
    def __init__(self, 
                 nome='indefinido', 
                 email='indefinido', 
                 tipo=TipoUsuario.MONITOR, 
                 matricula='indefinida', 
                 curso='indefinido', 
                 disciplinasAluno=None, 
                 areaDeAtuacao='indefinida', 
                 disciplinasMinistradas=None, 
                 disciplinasMonitoradas=None):
        # Chamando o inicializador de Aluno e Professor usando super()
        super().__init__(nome, email, tipo, matricula, curso, disciplinasAluno or [])

        # Inicializando atributos exclusivos de Professor
        self._areaDeAtuacao = areaDeAtuacao
        self._disciplinasMinistradas = disciplinasMinistradas or []

        # Inicializando atributos exclusivos do Monitor
        self._disciplinasMonitoradas = disciplinasMonitoradas or []

    def listarDisciplinasMonitoradas(self):
        # Método para listar as disciplinas monitoradas pelo monitor
        if not self._disciplinasMonitoradas:
            return "Nenhuma disciplina está sendo monitorada no momento."
        return f"Disciplinas Monitoradas: {', '.join(self._disciplinasMonitoradas)}"
