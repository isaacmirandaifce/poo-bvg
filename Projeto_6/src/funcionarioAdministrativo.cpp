#include "../include/funcionarioaAdministrativo.h"
#include <iostream>

// Construtor padrão
FuncionarioAdministrativo::FuncionarioAdministrativo()
    : UsuarioAutenticavel("", "", TipoUsuario::FUNCIONARIO_ADMINISTRATIVO, ""), departamento(""), cargo("") {}

// Construtor parametrizado
FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string nome, const std::string email, TipoUsuario tipo, std::string senha, const std::string departamento, const std::string cargo)
    : UsuarioAutenticavel(nome, email, TipoUsuario::FUNCIONARIO_ADMINISTRATIVO, senha), departamento(departamento), cargo(cargo) {}

// Sobrescrita de gerarRelatorio
void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "Funcionario Administrativo: " << nome << "\n"
              << "Departamento: " << departamento << "\n"
              << "Cargo: " << cargo << "\n";
}


bool FuncionarioAdministrativo::autenticar(const std::string& senha) const {
    return senha == getSenha(); // Usa o getter para acessar a senha armazenada
}