#ifndef FUNCIONARIOADMIN_H
#define FUNCIONARIOADMIN_H
#include <string>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
class FuncionarioAdministrativo : public UsuarioAutenticavel, public Relatorio {
private:
    std::string departamento;
    std::string cargo;
public:
    FuncionarioAdministrativo(std::string n,std::string s,std::string dep,std::string c)
        : UsuarioAutenticavel(n,s,TipoUsuario::FUNCIONARIO_ADMINISTRATIVO), departamento(dep), cargo(c) {}
    bool autenticar(const std::string& s) override { return s==senha; }
    void gerarRelatorio() const override {
        printf("Funcionario: %s\\nDepartamento: %s\\nCargo: %s\\n", nome.c_str(), departamento.c_str(), cargo.c_str());
    }
};
#endif
