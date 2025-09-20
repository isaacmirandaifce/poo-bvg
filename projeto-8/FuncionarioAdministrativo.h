#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H

#include <string>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class FuncionarioAdministrativo : public UsuarioAutenticavel, public Relatorio {
private:
    std::string departamento;
    std::string cargo;

public:
    FuncionarioAdministrativo(std::string nome, std::string email, std::string senha, std::string departamento, std::string cargo);

    // Overrides
    bool autenticar(const std::string& senha) override;
    void gerarRelatorio() override;
};

#endif // FUNCIONARIOADMINISTRATIVO_H
