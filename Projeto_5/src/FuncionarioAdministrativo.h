#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H

#include "Usuario.h"

class FuncionarioAdministrativo : public Usuario {

private:
    string departamento;
    string cargo;

public:
    FuncionarioAdministrativo();

    FuncionarioAdministrativo(string nome,
                              string email,
                              string departamento,
                              string cargo);

    void gerarRelatorio() override;

    ~FuncionarioAdministrativo();
};

#endif