from src.aluno import Aluno
from src.filtro import Filtro

if __name__ == "__main__":
    alunosFiltro = Filtro[Aluno]()
    filtro_professores = Filtro()
    alunosFiltro.adicionar_elemento(Aluno("João", "12345"))
    alunosFiltro.adicionar_elemento(Aluno("Maria", "vasco123"))

    alunosFiltro.elementos[0].historico.adicionar_disciplina("Matemática", 2022, 9.0)
    alunosFiltro.elementos[1].historico.adicionar_disciplina("Matemática", 2022, 7.5)
    def media_maior_que_7(aluno):
        for d in aluno.historico.disciplinas:
            if d["nome"] == "Matemática" and d["nota"] > 7.0:
                return True
        return False
    
  
    def ministra_disciplina(professor, nome_disciplina):
        return nome_disciplina in professor.disciplinas  

    professores_matematica = filtro_professores.filtrar_por_condicao(
        lambda p: ministra_disciplina(p, "Matemática")
    )
    for professor in professores_matematica:
        print(f"{professor.nome} ministra Matemática")
        
    aprovados = alunosFiltro.filtrar_por_condicao(media_maior_que_7)
    for aluno in aprovados:
        print(f"{aluno.nome} aprovado em Matemática")