#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"

class Aluno : public Usuario {
private:
    string curso;

public:
    Aluno(string nome, string id, string curso);
    void exibirInformacoes() const override;
    string getCurso() const { return curso; }
};

#endif // ALUNO_H
