#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include "TipoUsuario.h"

class Professor : public UsuarioAutenticavel, public Relatorio {
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
