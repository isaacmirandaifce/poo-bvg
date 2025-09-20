#include "FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo(std::string nome, std::string email, std::string senha, std::string departamento, std::string cargo)
    : UsuarioAutenticavel(nome, email, TipoUsuario::FUNCIONARIO_ADMINISTRATIVO, senha), departamento(departamento), cargo(cargo) {
}

bool FuncionarioAdministrativo::autenticar(const std::string& senha) {
    return this->getSenha() == senha;
}

void FuncionarioAdministrativo::gerarRelatorio() {
    std::cout << "--- Relatorio Funcional ---\n"
              << "Nome: " << this->nome << "\n"
              << "Departamento: " << this->departamento << "\n"
              << "Cargo: " << this->cargo << "\n";
}
