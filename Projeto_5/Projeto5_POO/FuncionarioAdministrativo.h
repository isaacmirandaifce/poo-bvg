#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Usuario.h"

class FuncionarioAdministrativo : public Usuario {
private:
    string departamento;
    string cargo;

public:
    FuncionarioAdministrativo(string n, string e, string d, string c);
    void gerarRelatorio() const override;
};

#endif

