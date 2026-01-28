#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include "UsuarioAutenticavel.h"

using namespace std;

class FuncionarioAdministrativo : public UsuarioAutenticavel {
private:
    string departamento;
    string cargo;

public:
    FuncionarioAdministrativo();
    FuncionarioAdministrativo(string nome, string email, string senha, string departamento, string cargo);

    bool autenticar(string senha) override;
    void gerarRelatorio() const override;
};

#endif
