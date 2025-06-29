#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <iostream>

class FuncionarioAdministrativo : public UsuarioAutenticavel, public Relatorio {
public:
    FuncionarioAdministrativo(std::string nome, std::string senha)
        : UsuarioAutenticavel(nome, TipoUsuario::FUNCIONARIO_ADMINISTRATIVO, senha) {}

    bool autenticar(std::string senhaDigitada) const override {
        return senhaDigitada == senha;
    }

    void gerarRelatorio() const override {
        std::cout << "Relatório do funcionário administrativo: " << nome << "\n";
        std::cout << "Gerenciando documentos e cadastros.\n";
    }
};

#endif
