#ifndef USUARIOAUDITOR_H
#define USUARIOAUDITOR_H

#include "../base/UsuarioAutenticavel.h"
#include "../interfaces/Relatorio.h"
#include <iostream>

class UsuarioAuditor : public UsuarioAutenticavel, public Relatorio {
public:
    UsuarioAuditor(int id, std::string user) : UsuarioAutenticavel(id, user) {}

    bool autenticar(std::string senha) override {
        return senha == "audit123";
    }

    void gerarRelatorio() const override {
        std::cout << "[Relatorio AUDITOR] Escopo: Varredura de integridade. Chave Publica: RSA-2048-PUB\n";
    }
};

#endif
