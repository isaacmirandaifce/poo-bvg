#include "SistemaAcademico.h"
#include "Persistencia.h"
#include <iostream>

void SistemaAcademico::addAluno(const Aluno& a) {
    getAlunosMut().push_back(a);
    if (persistencia) persistencia->saveAll(*this);
}

void SistemaAcademico::addProfessor(const Professor& p) {
    getProfessoresMut().push_back(p);
    if (persistencia) persistencia->saveAll(*this);
}

void SistemaAcademico::addDisciplina(const Disciplina& d) {
    getDisciplinasMut().push_back(d);
    if (persistencia) persistencia->saveAll(*this);
}

void SistemaAcademico::listarResumo() const {
    std::cout << "Alunos: " << alunos.size()
              << " | Professores: " << professores.size()
              << " | Disciplinas: " << disciplinas.size() << std::endl;
}
