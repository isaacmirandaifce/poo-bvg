#include "FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo() : UsuarioAutenticavel(), departamento(""), cargo("") {}

FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome, const std::string& email, const std::string& senha,
                                                     const std::string& departamento, const std::string& cargo)
    : UsuarioAutenticavel(nome, email, senha), departamento(departamento), cargo(cargo) {}

bool FuncionarioAdministrativo::autenticar(const std::string& senha) const {
    return this->senha == senha;
}

void FuncionarioAdministrativo::exibirInformacoes() const {
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Departamento: " << departamento << "\n";
    std::cout << "Cargo: " << cargo << "\n";
}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "Relatório do Funcionário Administrativo:\n";
    exibirInformacoes();
}