#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include <string>
#include <iostream>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class FuncionarioAdministrativo : public UsuarioAutenticavel, public Relatorio {
private:
    std::string setor;

public:
    FuncionarioAdministrativo(std::string nome, std::string email, std::string senha, std::string setor);

    bool autenticar(std::string senha) const override;
    void gerarRelatorio() const override;
};

#endif
