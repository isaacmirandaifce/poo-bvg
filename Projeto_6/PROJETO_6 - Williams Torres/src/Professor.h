#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class Professor : public UsuarioAutenticavel, public Relatorio {
private:
    std::string departamento;

public:
    Professor(const std::string& nome, const std::string& senha, const std::string& departamento);
    bool autenticar(const std::string& senha) const override;
    std::string gerarRelatorio() const override;
};

#endif // PROFESSOR_H