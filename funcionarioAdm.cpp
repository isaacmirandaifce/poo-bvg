#include "funcionarioAdm.h"
#include <iostream>

// Construtor com inicialização da classe base Usuario
funcionarioAdm::funcionarioAdm(std::string nome, std::string email,
                                                     std::string depto, std::string cargo)
    : Usuario(nome, email, "Funcionario Administrativo"),
      departamento(depto), cargo(cargo) {}

  // Sobrescrita do método virtual puro gerarRelatorio
void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "\n=== Relatório do Funcionário Administrativo ===\n";
    std::cout << "Nome: " << nome << "\nDepartamento: " << departamento
              << "\nCargo: " << cargo << "\n";
}
