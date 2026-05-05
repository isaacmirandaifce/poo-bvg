#ifndef FUNCIONARIO_ADM_H
#define FUNCIONARIO_ADM_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class FuncionarioAdministrativo : public UsuarioAutenticavel, public Relatorio {
private:
    std::string cargo;

public:
    FuncionarioAdministrativo(std::string nome, std::string email, std::string senha, std::string cargo);

    bool autenticar(std::string senhaDigitada) override;
    void gerarRelatorio() const override;
};

#endif
