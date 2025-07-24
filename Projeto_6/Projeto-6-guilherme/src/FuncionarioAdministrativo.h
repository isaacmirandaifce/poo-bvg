#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include "Usuario.h"
#include "Relatorio.h"
#include <string>

class FuncionarioAdministrativo : public Usuario, public Relatorio {
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
