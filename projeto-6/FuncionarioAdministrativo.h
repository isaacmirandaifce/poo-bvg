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
    // Construtor
    FuncionarioAdministrativo(std::string nome, std::string email, std::string senha, std::string departamento, std::string cargo);

    // Implementação dos "contratos" das classes pai
    bool autenticar(const std::string& senha) override;
    void gerarRelatorio() override;
};

#endif // FUNCIONARIOADMINISTRATIVO_H
