#ifndef FUNCIONARIO_ADMIN_H
#define FUNCIONARIO_ADMIN_H

#include "Usuario.h"

class FuncionarioAdministrativo : public Usuario {
private:
    std::string departamento;
    std::string cargo;

public:
    FuncionarioAdministrativo();
    FuncionarioAdministrativo(std::string nome, std::string email,
                               std::string departamento, std::string cargo);

    void gerarRelatorio() const override;
};

#endif
