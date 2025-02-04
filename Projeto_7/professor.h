#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "usuario.h"

class Professor : public Usuario {
private:
    string disciplina;

public:
    Professor(string nome, string id, string disciplina);
    void exibirInformacoes() const override;
    string getDisciplina() const { return disciplina; }
};

#endif 
