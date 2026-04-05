#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class Professor : public UsuarioAutenticavel, public Relatorio {
public:
    Professor(std::string nome, std::string matricula, std::string senha);

    bool autenticar(const std::string& senha) const override;
    void gerarRelatorio() const override;
};

#endif
