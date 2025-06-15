#ifndef FUNCIONARIO_ADMINISTRATIVO_HPP
#define FUNCIONARIO_ADMINISTRATIVO_HPP

#include "Usuario.hpp"

class FuncionarioAdministrativo : public Usuario {
private:
    std::string departamento;
    std::string cargo;

public:
    FuncionarioAdministrativo();
    FuncionarioAdministrativo(const std::string& nome, const std::string& email, const std::string& departamento, const std::string& cargo);

    void gerarRelatorio() const override;
};

#endif // FUNCIONARIO_ADMINISTRATIVO_HPP
