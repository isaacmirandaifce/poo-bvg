#include "FuncionarioAdministrativo.h"

FuncionarioAdministrativo::FuncionarioAdministrativo(std::string nome, std::string departamento) : nome(nome), departamento(departamento) {}

std::string FuncionarioAdministrativo::getNome() const {
    return nome;
}

std::string FuncionarioAdministrativo::getDepartamento() const {
    return departamento;
}