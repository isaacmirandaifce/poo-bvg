
#include "../include/FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo(std::string nome, std::string login, std::string senha)
    : UsuarioAutenticavel(nome, login, senha) {}

bool FuncionarioAdministrativo::autenticar(std::string senhaTentativa) {
    return senha == senhaTentativa;
}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "Relatório do Funcionário Administrativo: " << nome << std::endl;
}
