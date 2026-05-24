#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"
#include <vector>

class Professor : virtual public Usuario {
protected:
    string areaDeAtuacao;
    vector<string> disciplinasMinistradas;

public:
    Professor();
    Professor(string nome, string email,
               string areaDeAtuacao);

    void adicionarDisciplina(string disciplina);

    void gerarRelatorio() override;

    virtual ~Professor();
};

#endif