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

public:
    Aluno();
    Aluno(const std::string& nome, const std::string& matricula, const std::string& curso);

    void exibirInformacoes() const;
    void adicionarDisciplina(const Disciplina& disciplina);

    // Getter para disciplinas (opcional se precisar manipular na main)
    std::vector<Disciplina> getDisciplinas() const;

private:
    std::vector<Disciplina> disciplinas; // Lista de disciplinas associadas
};

#endif // ALUNO_H
