#include "FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo(std::string nome, std::string departamento, std::string cargo, std::string senha)
    : UsuarioAutenticavel(senha), nome(nome), departamento(departamento), cargo(cargo), tipo(TipoUsuario::FUNCIONARIO_ADMINISTRATIVO) {}

bool FuncionarioAdministrativo::autenticar(std::string senha) const {
    return this->senha == senha;
}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "Relatorio do Funcionario Administrativo:\n";
    std::cout << "Nome: " << nome << "\nDepartamento: " << departamento << "\nCargo: " << cargo << "\n";
}