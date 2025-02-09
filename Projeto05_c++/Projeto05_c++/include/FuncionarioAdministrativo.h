#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H

#include "Usuario.h"
#include <string>

class FuncionarioAdministrativo : public Usuario {
private:
    std::string departamento;
    std::string cargo;

public:
    // Construtores
    FuncionarioAdministrativo();
    FuncionarioAdministrativo(const std::string& nome, const std::string& email, const std::string& departamento, const std::string& cargo);

    // Métodos
    void gerarRelatorio() const override;
};

#endif // FUNCIONARIOADMINISTRATIVO_H