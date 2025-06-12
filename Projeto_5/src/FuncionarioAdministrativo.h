#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H

#include "Usuario.h"

class FuncionarioAdministrativo : public Usuario {
protected:
    std::string departamento;
    std::string cargo;

public:
    FuncionarioAdministrativo(std::string nome, std::string email, std::string departamento, std::string cargo);

    void gerarRelatorio() const override;
};

#endif
