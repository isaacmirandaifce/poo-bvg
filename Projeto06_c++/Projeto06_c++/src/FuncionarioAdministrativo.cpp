#include "../include/FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo() : UsuarioAutenticavel(), departamento(""), cargo("") {}

FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome, const std::string& email, const std::string& departamento, const std::string& cargo)
    : UsuarioAutenticavel(nome, email, "Funcionario Administrativo", ""), departamento(departamento), cargo(cargo) {}

FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome, const std::string& email, const std::string& departamento, const std::string& cargo, const std::string& senha)
    : UsuarioAutenticavel(nome, email, "Funcionario Administrativo", senha), departamento(departamento), cargo(cargo) {}

bool FuncionarioAdministrativo::autenticar(const std::string& senha) const {
    return verificarSenha(senha);
}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "Relatorio do Funcionario Administrativo:\n"
              << "Nome: " << nome << "\n"
              << "Departamento: " << departamento << "\n"
              << "Cargo: " << cargo << "\n";
}