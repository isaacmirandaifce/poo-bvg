#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include "UsuarioAutenticavel.h"
#include <string>

// Classe derivada FuncionarioAdministrativo
class FuncionarioAdministrativo : public UsuarioAutenticavel {
private:
    std::string departamento;
    std::string cargo;

public:
    // Construtores
    FuncionarioAdministrativo();
    FuncionarioAdministrativo(const std::string nome, const std::string email, TipoUsuario tipo, std::string senha, const std::string departamento, const std::string cargo);

    // Sobrescrita de gerarRelatorio
    void gerarRelatorio() const override;
    bool autenticar(const std::string& senha) const override;
};

#endif // FUNCIONARIO_ADMINISTRATIVO_H
