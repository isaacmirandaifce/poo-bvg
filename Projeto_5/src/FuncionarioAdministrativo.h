#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H

#include "Usuario.h"

class FuncionarioAdministrativo : public Usuario {
private:
    std::string departamento;
    std::string cargo;

public:
    FuncionarioAdministrativo();
    FuncionarioAdministrativo(const std::string& nome, const std::string& email, const std::string& departamento, const std::string& cargo);

    virtual void gerarRelatorio() const override;
};

#endif // FUNCIONARIOADMINISTRATIVO_H
