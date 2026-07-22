#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H

#include <string>
#include "Usuario.h"

class FuncionarioAdministrativo : public Usuario {
private:
    std::string departamento;
    std::string cargo;

public:
    FuncionarioAdministrativo();
    FuncionarioAdministrativo(std::string nome, std::string email, std::string departamento, std::string cargo);

    // Sobrescrita: implementacao do relatorio geral herdado de Usuario
    void gerarRelatorio() const override;
};

#endif // FUNCIONARIOADMINISTRATIVO_H
