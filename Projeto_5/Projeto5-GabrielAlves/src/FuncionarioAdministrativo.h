#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H

#include "Usuario.h"

class FuncionarioAdministrativo : public Usuario {
private:
    std::string departamento;
    std::string cargo;

public:
    FuncionarioAdministrativo(std::string nome, std::string email, std::string depto, std::string cargo);

    // Sobrescrita do método virtual puro. 
    void gerarRelatorio() const override;
};

#endif // FUNCIONARIOADMINISTRATIVO_H