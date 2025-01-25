#include "FuncionarioAdministrativo.h"
#include <sstream>

FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome, const std::string& senha, const std::string& setor)
    : UsuarioAutenticavel(nome, senha), setor(setor) {}

bool FuncionarioAdministrativo::autenticar(const std::string& senha) const {
    return this->senha == senha;
}

std::string FuncionarioAdministrativo::gerarRelatorio() const {
    std::ostringstream oss;
    oss << "Relatório de Funcionário Administrativo - Nome: " << nome << " - Setor: " << setor;
    return oss.str();
}
