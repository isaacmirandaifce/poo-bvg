from filtro import Filtro
from aluno import Aluno
from professor import Professor

if __name__ == "__main__":
    filtro_alunos = Filtro[Aluno]()
    filtro_professores = Filtro[Professor]()

    filtro_alunos.adicionar_elemento(Aluno("João", 8.5, ["POO", "Direito Digital"]))
    filtro_alunos.adicionar_elemento(Aluno("Márcia", 6.9, ["Eng. de Software", "Projeto Social"]))

    filtro_professores.adicionar_elemento(Professor("Thales Siqueira", "Direito Digital"))
    filtro_professores.adicionar_elemento(Professor("Jéssica", "Eng. de Software"))

    alunos_aprovados = filtro_alunos.filtrar_por_condicao(lambda aluno: aluno.media > 7.0)
    print("Alunos aprovados:")
    filtro_alunos.imprimir_todos(lambda aluno: print(aluno) if aluno in alunos_aprovados else None)

    disciplina_especifica = "Matemática"
    professores_matematica = filtro_professores.filtrar_por_condicao(lambda prof: prof.disciplina == disciplina_especifica)
    print("\nProfessores de Matemática:")
    filtro_professores.imprimir_todos(lambda prof: print(prof) if prof in professores_matematica else None)