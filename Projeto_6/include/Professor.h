#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include "TipoUsuario.h"
#include <string>

class Professor : public UsuarioAutenticavel, public Relatorio {
public:
    Professor(const std::string& nome, const std::string& senha);
    bool autenticar(const std::string& senha) const override;
    void gerarRelatorio() const override;
    TipoUsuario getTipo() const;

private:
    std::string nome;
    std::string senha;
};

#endif