#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include "Usuario.h"

class FuncionarioAdministrativo : public Usuario {
protected:
    std::string departamento;
    std::string cargo;

public:
    FuncionarioAdministrativo();
    FuncionarioAdministrativo(std::string n, std::string e, std::string t, std::string dept, std::string carg);
    virtual ~FuncionarioAdministrativo() {}

    void gerarRelatorio() override;
};

#endif