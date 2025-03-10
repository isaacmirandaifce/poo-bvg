#include "SinalHandler.h"
#include "Persistencia.h"

std::vector<Aluno> SinalHandler::alunos;
std::vector<Professor> SinalHandler::professores;
std::vector<Disciplina> SinalHandler::disciplinas;

void SinalHandler::setDados(const std::vector<Aluno>& alunos, 
                            const std::vector<Professor>& professores, 
                            const std::vector<Disciplina>& disciplinas) {
    SinalHandler::alunos = alunos;
    SinalHandler::professores = professores;
    SinalHandler::disciplinas = disciplinas;
}

void SinalHandler::tratador(int sinal) {
    Persistencia::salvarAlunos("data/alunos.txt", SinalHandler::alunos);
    Persistencia::salvarProfessores("data/professores.txt", SinalHandler::professores);
    Persistencia::salvarDisciplinas("data/disciplinas.txt", SinalHandler::disciplinas);
}
