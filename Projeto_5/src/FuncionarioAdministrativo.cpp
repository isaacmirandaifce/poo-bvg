#include "FuncionarioAdministrativo.h"
#include <iostream>
void FuncionarioAdministrativo::gerarRelatorio() {
    std::cout << "Funcionario: " << nome << "\nDepartamento: " << departamento << "\nCargo: " << cargo << std::endl;
}
