#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H

#include "Usuario.h"

class FuncionarioAdministrativo : public Usuario {
private:
    std::string departamento;
    std::string cargo;

public:
    // Construtor padrão
    FuncionarioAdministrativo();

    // Construtor parametrizado
    FuncionarioAdministrativo(const std::string& nome, const std::string& email, const std::string& departamento, const std::string& cargo);

    // Sobrescrita do método gerarRelatorio
    void gerarRelatorio() const override;
};

#endif // FUNCIONARIOADMINISTRATIVO_H