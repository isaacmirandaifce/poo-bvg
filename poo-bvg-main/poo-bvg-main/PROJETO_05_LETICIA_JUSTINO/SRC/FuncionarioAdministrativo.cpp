#include "FuncionarioAdministrativo.h"
#include <iostream>

// Construtor padrão: inicializa os atributos vazios
FuncionarioAdministrativo::FuncionarioAdministrativo()
    : Usuario(), departamento(""), cargo("") {}

// Construtor com parâmetros: recebe nome, email, departamento e cargo
// Passa "Funcionario" para o tipo de usuário na classe base Usuario
FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome,
                                                     const std::string& email,
                                                     const std::string& departamento,
                                                     const std::string& cargo)
    : Usuario(nome, email, "Funcionario"), // chama o construtor da classe base
      departamento(departamento),
      cargo(cargo) {}

// Método para gerar relatório básico do funcionário
void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "Nome: " << nome
              << "\nDepartamento: " << departamento
              << "\nCargo: " << cargo
              << std::endl;
}