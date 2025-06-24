#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Usuario.h"

class FuncionarioAdministrativo : public Usuario {
private:
    std::string departamento;
    std::string cargo;

public:
    FuncionarioAdministrativo();
    FuncionarioAdministrativo(const std::string& nome, const std::string& email,
    const std::string& departamento, const std::string& cargo);

    void gerarRelatorio() const override;
};

#endif