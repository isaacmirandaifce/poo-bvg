#ifndef SISTEMA_ACADEMICO_H
#define SISTEMA_ACADEMICO_H

#include <vector>
#include <string>
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"

class Persistencia; // forward decl

class SistemaAcademico {
    std::vector<Aluno> alunos;
    std::vector<Professor> professores;
    std::vector<Disciplina> disciplinas;
    Persistencia* persistencia { nullptr }; // não-owned
public:
    SistemaAcademico() = default;

    void setPersistencia(Persistencia* p) { persistencia = p; }

    const std::vector<Aluno>& getAlunos() const { return alunos; }
    const std::vector<Professor>& getProfessores() const { return professores; }
    const std::vector<Disciplina>& getDisciplinas() const { return disciplinas; }

    std::vector<Aluno>& getAlunosMut() { return alunos; }
    std::vector<Professor>& getProfessoresMut() { return professores; }
    std::vector<Disciplina>& getDisciplinasMut() { return disciplinas; }

    void addAluno(const Aluno& a);
    void addProfessor(const Professor& p);
    void addDisciplina(const Disciplina& d);

    // Métodos utilitários simples
    void listarResumo() const;
};

#endif // SISTEMA_ACADEMICO_H
