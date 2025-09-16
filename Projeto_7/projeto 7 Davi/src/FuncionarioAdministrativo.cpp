#include "FuncionarioAdministrativo.h"

FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome, const std::string& setor)
    : nome(nome), setor(setor) {}

const std::string& FuncionarioAdministrativo::getNome() const {
    return nome;
}

const std::string& FuncionarioAdministrativo::getSetor() const {
    return setor;
}

void FuncionarioAdministrativo::imprimir() const {
    std::cout << "Funcionário Administrativo: " << nome << " | Setor: " << setor << std::endl;
}
