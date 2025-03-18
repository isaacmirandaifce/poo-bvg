#include "FuncionarioAdministrativo.h"

// Construtor padrão
FuncionarioAdministrativo::FuncionarioAdministrativo() : Usuario(), departamento(""), cargo("") {}

// Construtor parametrizado
FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome, const std::string& email,
                                                     const std::string& departamento, const std::string& cargo)
    : Usuario(nome, email, "Funcionario Administrativo"), departamento(departamento), cargo(cargo) {}

// Sobrescrita do método gerarRelatorio
void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "Relatório do Funcionário Administrativo\n";
    std::cout << "Nome: " << nome << "\n"
              << "Departamento: " << departamento << "\n"
              << "Cargo: " << cargo << "\n";
}
