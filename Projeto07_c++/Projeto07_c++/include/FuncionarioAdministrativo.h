#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H

#include "UsuarioAutenticavel.h"
#include <string>

class FuncionarioAdministrativo : public UsuarioAutenticavel {
private:
    std::string departamento;
    std::string cargo;

public:
    // Construtores
    FuncionarioAdministrativo();
    FuncionarioAdministrativo(const std::string& nome, const std::string& email, const std::string& departamento, const std::string& cargo);
    FuncionarioAdministrativo(const std::string& nome, const std::string& email, const std::string& departamento, const std::string& cargo, const std::string& senha);

    // Métodos
    void gerarRelatorio() const override;
    bool autenticar(const std::string& senha) const override;
};

#endif // FUNCIONARIOADMINISTRATIVO_H