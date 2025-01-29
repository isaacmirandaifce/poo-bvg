#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class FuncionarioAdministrativo : public UsuarioAutenticavel, public Relatorio {
private:
    std::string setor;

public:
    FuncionarioAdministrativo(const std::string& nome, const std::string& senha, const std::string& setor);
    bool autenticar(const std::string& senha) const override;
    std::string gerarRelatorio() const override;
};

#endif // FUNCIONARIO_ADMINISTRATIVO_H