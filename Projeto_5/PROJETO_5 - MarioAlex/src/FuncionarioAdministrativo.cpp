#include "FuncionarioAdministrativo.h"

FuncionarioAdministrativo::FuncionarioAdministrativo()
    : Usuario(), departamento("Indefinido"), cargo("Desconhecido") {}

FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome, const std::string& email,
     const std::string& departamento, const std::string& cargo)
    : Usuario(nome, email, "Funcionário"), departamento(departamento), cargo(cargo) {}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "[Funcionário] " << nome << " - " << cargo << " no depto. " << departamento << std::endl;
}