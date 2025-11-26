#ifndef FUNCADMIN_H
#define FUNCADMIN_H

#include "Usuario.h"

class FuncionarioAdministrativo : public Usuario {
private:
    string departamento;
    string cargo;

public:
    FuncionarioAdministrativo();
    FuncionarioAdministrativo(const string &nome, const string &email, const string &departamento, const string &cargo);
    ~FuncionarioAdministrativo();

    void gerarRelatorio() const override;

    string getDepartamento() const;
    string getCargo() const;
};

#endif // FUNCADMIN_H