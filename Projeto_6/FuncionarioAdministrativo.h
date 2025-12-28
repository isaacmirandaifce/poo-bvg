#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include <string>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include "TipoUsuario.h"

class FuncionarioAdministrativo : public UsuarioAutenticavel, public Relatorio {
private:
    std::string nome;
    std::string senha;

public:
    bool autenticar(const std::string& senha) override {
        return this->senha == senha;
    }

    void gerarRelatorio() const override {
    }
};

#endif
