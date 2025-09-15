#ifndef FUNCIONARIO_ADM_H
#define FUNCIONARIO_ADM_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <string>

class FuncionarioAdm : public UsuarioAutenticavel, public Relatorio {
private:
    std::string setor;

public:
    FuncionarioAdm(std::string nome, std::string email, std::string senha, std::string setor);

    bool autenticar(std::string senhaDigitada) const override;
    void gerarRelatorio() const override;
};

#endif