#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <string>
using namespace std;

class Aluno : public Usuario {
private:
    string curso;
    int matricula;

public:
    Aluno();
    Aluno(string nome, string email, string curso, int matricula);

    string getCurso() const;
    int getMatricula() const;

    void gerarRelatorio() const override;
};

#endif
