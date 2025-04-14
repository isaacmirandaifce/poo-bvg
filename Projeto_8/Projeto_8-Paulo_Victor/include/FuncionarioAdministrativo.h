#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include "TipoUsuario.h"
#include <string>

class FuncionarioAdministrativo : public UsuarioAutenticavel, public Relatorio {
private:
    std::string nome;
    std::string departamento;
    std::string cargo;
    TipoUsuario tipo;

public:
    FuncionarioAdministrativo(std::string nome, std::string departamento, std::string cargo, std::string senha);
    bool autenticar(std::string senha) const override;
    void gerarRelatorio() const override;
};

#endif