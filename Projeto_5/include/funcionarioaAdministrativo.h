#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include "Usuario.h"
#include <string>

// Classe derivada FuncionarioAdministrativo
class FuncionarioAdministrativo : public Usuario {
private:
    std::string departamento;
    std::string cargo;

public:
    // Construtores
    FuncionarioAdministrativo();
    FuncionarioAdministrativo(const std::string& nome, const std::string& email, const std::string& tipo, const std::string& departamento, const std::string& cargo);

    // Sobrescrita de gerarRelatorio
    void gerarRelatorio() const override;
};

#endif // FUNCIONARIO_ADMINISTRATIVO_H
