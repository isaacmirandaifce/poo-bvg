#include "FuncionarioAdministrativo.h"

FuncionarioAdministrativo::FuncionarioAdministrativo() : UsuarioAutenticavel() {
    departamento = "NULL";
    cargo = "NULL";
}

FuncionarioAdministrativo::FuncionarioAdministrativo(string nome, string email, string senha, string departamento, string cargo)
    : UsuarioAutenticavel(nome, email, TipoUsuario::FUNCIONARIO_ADMINISTRATIVO, senha) {
    this->departamento = departamento;
    this->cargo = cargo;
}

bool FuncionarioAdministrativo::autenticar(string senha) {
    return this->senha == senha;
}

void FuncionarioAdministrativo::gerarRelatorio() const {
    cout << "\n--- RELATÓRIO FUNCIONÁRIO ---\n";
    cout << "Nome: " << nome << endl;
    cout << "Departamento: " << departamento << endl;
    cout << "Cargo: " << cargo << endl;
}
