#ifndef FUNCIONARIO_ADM_H
#define FUNCIONARIO_ADM_H

#include "Usuario.h"

class FuncionarioAdministrativo : public Usuario {
private:
    std::string departamento;
    std::string cargo;

public:
    FuncionarioAdministrativo(std::string nome, std::string email, std::string departamento, std::string cargo);

    void gerarRelatorio() override;
};

#endif
