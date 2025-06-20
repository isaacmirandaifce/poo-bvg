#include "funcionarioadministrativo.h"
#include <iostream>

funcionarioadministrativo::funcionarioadministrativo() {}

funcionarioadministrativo::funcionarioadministrativo(std::string nome, std::string email, std::string departamento, std::string cargo)
    : usuario(nome, email, "funcionario"), departamento(departamento), cargo(cargo) {}

void funcionarioadministrativo::gerarRelatorio() const {
    std::cout << "Funcionario: " << nome
              << "\nDepartamento: " << departamento
              << "\nCargo: " << cargo << "\n";
}
