#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include "Usuario.h"

// declaração da classe FuncionarioAdministrativo que herda a classe Usuario.
class FuncionarioAdministrativo : public Usuario {
private:
    string departamento;

public:
    FuncionarioAdministrativo(string nome, string id, string departamento);
    void exibirInformacoes() const override;
    string getDepartamento() const { return departamento; }
};

#endif