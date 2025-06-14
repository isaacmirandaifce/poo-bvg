#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H

#include "../Usuarios/Usuario.h"

class FuncionarioAdministrativo : public Usuario {
private:
    string departamento;
    string cargo;

public:
    FuncionarioAdministrativo();
    FuncionarioAdministrativo(string nome, string email, string tipo, string departamento, string cargo);
    void gerarRelatorio() override;
};

#endif