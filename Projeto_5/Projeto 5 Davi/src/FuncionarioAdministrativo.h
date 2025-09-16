#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include "Usuario.h"
#include <string>
using namespace std;

class FuncionarioAdministrativo : public Usuario {
private:
    string departamento;
    string cargo;

public:
    FuncionarioAdministrativo();
    FuncionarioAdministrativo(string nome, string email, string departamento, string cargo);
    void gerarRelatorio() const override; // corrigido aqui
};

#endif
