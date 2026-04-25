#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H

#include "Usuario.h"


// Declaração da classe FuncionarioAdministrativo que herda de Usuario
class FuncionarioAdministrativo : public Usuario {
private:
    std::string departamento;
    std::string cargo;

public:
    FuncionarioAdministrativo(std::string nome, std::string email,
                              std::string depto, std::string cargo);

    // SOBRESCRITA
    void gerarRelatorio() const override;
};

#endif
