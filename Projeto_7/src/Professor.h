#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class Professor : public UsuarioAutenticavel, public Relatorio {
private:
    std::string disciplina;

public:
    Professor(const std::string& nome,
              const std::string& email,
              const std::string& senha,
              const std::string& disciplina);

    bool autenticar(const std::string& senha) const override;
    void gerarRelatorio() const override;
};

#endif