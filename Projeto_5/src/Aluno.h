#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <vector>

class Aluno : virtual public Usuario {
protected:
    string matricula;
    string curso;
    vector<string> disciplinas;

public:
    Aluno();
    Aluno(string nome, string email, string matricula, string curso);

    void adicionarDisciplina(string disciplina);

    void gerarRelatorio() override;

    // SOBRECARGA
    void exibirInformacoes();
    void exibirInformacoes(float nota);

    virtual ~Aluno();
};

#endif