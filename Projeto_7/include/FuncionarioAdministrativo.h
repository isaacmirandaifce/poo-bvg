#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H
#include "Usuario.h"
#include "Relatorio.h"

class FuncionarioAdministrativo : public Usuario, public Relatorio {
    string departamento, cargo;
public:
    FuncionarioAdministrativo(string n, string e, string d, string c) : Usuario(n, e), departamento(d), cargo(c) {}
    void gerarRelatorio() const override;
};

#endif // FUNCIONARIOADMINISTRATIVO_H