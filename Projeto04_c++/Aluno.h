#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>
#include "Disciplina.h"

class Aluno {
private:
    std::string nome;
    std::string matricula;
    std::string curso;
    std::vector<Disciplina> disciplinas;

public:
    // Construtores
    Aluno();
    Aluno(const std::string& nome, const std::string& matricula, const std::string& curso);

    // Métodos
    void exibirInformacoes() const;
    void adicionarDisciplina(const Disciplina& disciplina);

    // Getters
    const std::string& getNome() const;
    const std::vector<Disciplina>& getDisciplinas() const;
};

#endif