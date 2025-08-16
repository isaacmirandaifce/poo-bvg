#include "FuncionarioAdministrativo.h"
#include <iostream>
using namespace std;

FuncionarioAdministrativo::FuncionarioAdministrativo() : UsuarioAutenticavel(), departamento(""), cargo(""), tipoUsuario(TipoUsuario::FUNCIONARIO_ADMINISTRATIVO) {}

FuncionarioAdministrativo::FuncionarioAdministrativo(string nome, string email, string tipo, string senha, string departamento, string cargo)
    : UsuarioAutenticavel(nome, email, tipo, senha), departamento(departamento), cargo(cargo), tipoUsuario(TipoUsuario::FUNCIONARIO_ADMINISTRATIVO) {}

void FuncionarioAdministrativo::gerarRelatorio() {
    cout << "=== RELATORIO DE FUNCIONARIO ADMINISTRATIVO ===" << endl;
    cout << "Nome: " << nome << ", Email: " << email << ", Tipo: " << tipo << endl;
    cout << "Departamento: " << departamento << ", Cargo: " << cargo << endl << endl;
}

bool FuncionarioAdministrativo::autenticar(string senhaTentativa) {
    return senhaTentativa == senha;
}