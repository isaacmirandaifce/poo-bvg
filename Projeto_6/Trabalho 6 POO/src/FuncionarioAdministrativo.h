#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H

#include <string>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class FuncionarioAdministrativo : public UsuarioAutenticavel, public Relatorio {
private:
    std::string departamento;
    std::string cargo;
    std::size_t senhaHash;

public:
    FuncionarioAdministrativo();
    FuncionarioAdministrativo(const std::string& nome, const std::string& email,
                             const std::string& departamento, const std::string& cargo);

    void setSenha(const std::string& senha);
    bool autenticar(const std::string& senha) const override;

    void gerarRelatorio() const override;
};

#endif // FUNCIONARIOADMINISTRATIVO_H
