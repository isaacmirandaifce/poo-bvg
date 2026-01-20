#include "FuncionarioAdministrativo.h"

FuncionarioAdministrativo::FuncionarioAdministrativo()
    : Usuario("", "", "FuncionarioAdministrativo"), departamento(""), cargo("") {}

FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome,
                                                     const std::string& email,
                                                     const std::string& departamento,
                                                     const std::string& cargo)
    : Usuario(nome, email, "FuncionarioAdministrativo"),
      departamento(departamento),
      cargo(cargo) {}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "===== RELATORIO (FUNCIONARIO ADM) =====\n";
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Departamento: " << departamento << "\n";
    std::cout << "Cargo: " << cargo << "\n";
    std::cout << "======================================\n\n";
}
