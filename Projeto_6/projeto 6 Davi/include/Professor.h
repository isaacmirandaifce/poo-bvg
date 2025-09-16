
#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class Professor : public UsuarioAutenticavel, public Relatorio {
public:
    Professor(std::string nome, std::string login, std::string senha);
    bool autenticar(std::string senha) override;
    void gerarRelatorio() const override;
};

#endif
