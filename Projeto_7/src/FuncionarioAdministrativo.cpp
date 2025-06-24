#include "FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome, const std::string& cargo)
    : nome(nome), cargo(cargo) {}

std::string FuncionarioAdministrativo::getNome() const {
    return nome;
}

std::string FuncionarioAdministrativo::getCargo() const {
    return cargo;
}

void FuncionarioAdministrativo::imprimir() const {
    std::cout << "Funcionario Administrativo: " << nome << " (Cargo: " << cargo << ")" << std::endl;
}