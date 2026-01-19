#ifndef FUNCADMIN_H
#define FUNCADMIN_H
#include <string>
#include "Usuario.h"
class FuncionarioAdministrativo : public Usuario {
public:
    std::string departamento;
    FuncionarioAdministrativo(std::string n, std::string e, std::string d): Usuario(n,e), departamento(d) {}
};
#endif
