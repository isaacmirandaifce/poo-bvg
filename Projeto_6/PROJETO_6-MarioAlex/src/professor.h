#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class Professor : public UsuarioAutenticavel, public Relatorio {
private:
    std::string disciplinaPrincipal;

public:
    Professor(std::string nome, std::string email, std::string senha, std::string disciplina);

    bool autenticar(std::string senhaDigitada) const override;
    void gerarRelatorio() const override;
};

#endif