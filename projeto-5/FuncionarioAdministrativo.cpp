#include "FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo(std::string nome, std::string email, std::string departamento, std::string cargo)
    : Usuario(nome, email, "Funcionario Administrativo"), departamento(departamento), cargo(cargo)
{

}

// Implementação da sobrescrita de gerarRelatorio()
void FuncionarioAdministrativo::gerarRelatorio()
{
    std::cout << "--- Relatório do Funcionário Administrativo ---" << std::endl;
    std::cout << "Nome: " << this->nome << std::endl; // 'nome' é acessível pois é 'protected'
    std::cout << "Departamento: " << this->departamento << std::endl;
    std::cout << "Cargo: " << this->cargo << std::endl;
}
