#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class FuncionarioAdministrativo : public UsuarioAutenticavel, public Relatorio {
public:
    FuncionarioAdministrativo(std::string nome, std::string matricula, std::string senha);

    bool autenticar(const std::string& senha) const override;
    void gerarRelatorio() const override;
};

#endif
