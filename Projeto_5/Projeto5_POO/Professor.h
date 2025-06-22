#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"
#include <vector>

class Professor : public virtual Usuario {
protected:
    string areaDeAtuacao;
    vector<string> disciplinasMinistradas;

public:
    Professor(string n, string e, string area);
    void adicionarDisciplina(string nome);
    void gerarRelatorio() const override;
};

#endif
