#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H
#include "Usuario.h"
#include <string>
class FuncionarioAdministrativo : public Usuario {
private:
    std::string departamento;
    std::string cargo;
public:
    FuncionarioAdministrativo() {}
    FuncionarioAdministrativo(std::string n, std::string e, std::string t, std::string d, std::string c)
    : Usuario(n,e,t), departamento(d), cargo(c) {}
    void gerarRelatorio() override;
};
#endif
