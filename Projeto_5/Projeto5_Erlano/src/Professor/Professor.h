#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "../Usuarios/Usuario.h"
#include <vector>

class Professor : public virtual Usuario {
protected:
    string areaDeAtuacao;
    vector<string> disciplinasMinistradas;

public:
    Professor();
    Professor(string nome, string email, string tipo, string areaDeAtuacao, vector<string> disciplinasMinistradas);
    void gerarRelatorio() override;
    string getAreaDeAtuacao();
};

#endif