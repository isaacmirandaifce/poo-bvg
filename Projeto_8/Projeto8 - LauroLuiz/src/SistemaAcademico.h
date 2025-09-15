#ifndef SISTEMA_ACADEMICO_H
#define SISTEMA_ACADEMICO_H

#include <vector>
#include <iostream>
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"
#include "Persistencia.h"

class SistemaAcademico {
private:
    std::vector<Aluno> alunos;
    std::vector<Professor> professores;
    std::vector<Disciplina> disciplinas;

public:
    SistemaAcademico();
    ~SistemaAcademico();

    // Métodos para gerenciar alunos
    void adicionarAluno(const Aluno& aluno);
    void listarAlunos() const;

    // Métodos para gerenciar professores
    void adicionarProfessor(const Professor& professor);
    void listarProfessores() const;

    // Métodos para gerenciar disciplinas
    void adicionarDisciplina(const Disciplina& disciplina);
    void listarDisciplinas() const;

    // Métodos de persistência
    void carregarDados();
    void salvarDados();

    // Getters para os vetores (para o tratador de sinais)
    std::vector<Aluno>& getAlunos() { return alunos; }
    std::vector<Professor>& getProfessores() { return professores; }
    std::vector<Disciplina>& getDisciplinas() { return disciplinas; }

    // Menu interativo
    void executarMenu();
};

#endif
