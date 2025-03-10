#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include "TipoUsuario.h"
#include <string>

class FuncionarioAdministrativo : public UsuarioAutenticavel, public Relatorio {
public:
    FuncionarioAdministrativo(const std::string& nome, const std::string& senha);
    bool autenticar(const std::string& senha) const override;
    void gerarRelatorio() const override;
    TipoUsuario getTipo() const;

private:
    std::string nome;
    std::string senha;
};

#endif 
