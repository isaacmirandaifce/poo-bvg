#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"
#include <string>
using namespace std;

class Professor : public Usuario {
private:
    string disciplina;
    string titulacao;

public:
    Professor();
    Professor(string nome, string email, string disciplina, string titulacao);

    string getDisciplina() const;
    string getTitulacao() const;

    void gerarRelatorio() const override;
};

#endif
