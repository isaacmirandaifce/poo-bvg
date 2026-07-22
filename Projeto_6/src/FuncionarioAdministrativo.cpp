#include <iostream>
#include "FuncionarioAdministrativo.h"

using namespace std;

FuncionarioAdministrativo::FuncionarioAdministrativo()
    : UsuarioAutenticavel(), departamento(""), cargo("") {}

FuncionarioAdministrativo::FuncionarioAdministrativo(string nome, string email, const string& senha,
                                                       string departamento, string cargo)
    : UsuarioAutenticavel(nome, email, TipoUsuario::FUNCIONARIO_ADMINISTRATIVO, senha),
      departamento(departamento), cargo(cargo) {}

bool FuncionarioAdministrativo::autenticar(string senha) {
    return validarSenha(senha);
}

void FuncionarioAdministrativo::gerarRelatorio() const {
    cout << "[Relatorio de Funcionario Administrativo - " << tipoUsuarioParaTexto(tipo) << "]" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Departamento: " << departamento << endl;
    cout << "Cargo: " << cargo << endl;
}
