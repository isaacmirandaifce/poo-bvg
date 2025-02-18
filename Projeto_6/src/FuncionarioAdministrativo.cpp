#include "FuncionarioAdministrativo.h"
#include <iostream>
using namespace std;

FuncionarioAdministrativo::FuncionarioAdministrativo(const string& nome, const string& email, const string& senha, const string& departamento, const string& cargo)
    : UsuarioAutenticavel(nome, email, senha, TipoUsuario::FUNCIONARIO_ADMINISTRATIVO), // Tipo correto
      departamento(departamento), cargo(cargo) {}

bool FuncionarioAdministrativo::autenticar(const string& senha) const {
    return this->senha == senha;
}

void FuncionarioAdministrativo::gerarRelatorio() const {
    cout << "Funcionário Administrativo: " << nome << "\nEmail: " << email 
         << "\nDepartamento: " << departamento << "\nCargo: " << cargo << endl;
}
