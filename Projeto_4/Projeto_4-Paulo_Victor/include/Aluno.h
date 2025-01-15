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
    Aluno();
    Aluno(const std::string &nome, const std::string &matricula, const std::string &curso);

    void adicionarDisciplina(const Disciplina &disciplina);
    void exibirInformacoes() const;

    std::string getNome() const;
    std::string getMatricula() const;
    std::string getCurso() const;
};

#endif