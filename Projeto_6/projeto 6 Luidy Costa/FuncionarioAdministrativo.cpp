#include "FuncionarioAdministrativo.h"
#include <iostream>

using namespace std;

FuncionarioAdministrativo::FuncionarioAdministrativo(string nome, string email, string senha, string cargo)
    : UsuarioAutenticavel(nome, email, TipoUsuario::FUNCIONARIO_ADMINISTRATIVO, senha), cargo(cargo) {}

bool FuncionarioAdministrativo::autenticar(string senhaDigitada) {
    return this->senha == senhaDigitada;
}

void FuncionarioAdministrativo::gerarRelatorio() const {
    cout << "=== Relatorio Administrativo ===" << endl;
    cout << "Funcionario: " << nome << endl;
    cout << "Cargo Atual: " << cargo << endl;
    cout << "================================" << endl;
}
