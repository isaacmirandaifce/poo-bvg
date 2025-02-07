#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H

#include "Usuario.h"
using namespace std;

class FuncionarioAdministrativo : public Usuario {
private:
    string departamento;
    string cargo;

public:
    FuncionarioAdministrativo(const string& nome, const string& email, const string& departamento, const string& cargo);

    // Sobrescrevendo gerarRelatorio
    void gerarRelatorio() const override;
};

#endif
