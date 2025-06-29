#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <iostream>

class Professor : public UsuarioAutenticavel, public Relatorio {
public:
    Professor(std::string nome, std::string senha)
        : UsuarioAutenticavel(nome, TipoUsuario::PROFESSOR, senha) {}

    bool autenticar(std::string senhaDigitada) const override {
        return senhaDigitada == senha;
    }

    void gerarRelatorio() const override {
        std::cout << "Relatório do professor: " << nome << "\n";
        std::cout << "Ministrando disciplinas atualmente.\n";
    }
};

#endif
