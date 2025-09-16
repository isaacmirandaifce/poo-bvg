#ifndef SISTEMAACADEMICO_H
#define SISTEMAACADEMICO_H

#include <vector>
#include <string>
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"

class SistemaAcademico {
public:
    // Carrega TODOS os dados na inicialização
    void carregarDados();
    // Salva TODOS os dados
    void salvarDados() const; 

    // Métodos para Alunos
    void adicionarAluno(const Aluno& aluno);
    void listarAlunos() const;

    // Métodos para Professores
    void adicionarProfessor(const Professor& prof);
    void listarProfessores() const;

    // Métodos para Disciplinas
    void adicionarDisciplina(const Disciplina& disc);
    void listarDisciplinas() const;

    void simularFalhaDeSegmentacao();

private:
    // Listas de dados
    std::vector<Aluno> alunos;
    std::vector<Professor> professores;
    std::vector<Disciplina> disciplinas;

    // Nomes dos arquivos
    const std::string ARQUIVO_ALUNOS = "alunos.csv";
    const std::string ARQUIVO_PROFESSORES = "professores.csv";
    const std::string ARQUIVO_DISCIPLINAS = "disciplinas.csv";
};

#endif // SISTEMAACADEMICO_H