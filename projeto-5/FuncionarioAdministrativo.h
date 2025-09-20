#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H

#include "Usuario.h"
#include <string>

class FuncionarioAdministrativo : public Usuario
{
    private:
        std::string departamento;
        std::string cargo;

    public:
        FuncionarioAdministrativo(std::string nome, std::string email, std::string departamento, std::string cargo);

        // Sobrescrita do método gerarRelatorio da classe base
        void gerarRelatorio() override;
};

#endif
