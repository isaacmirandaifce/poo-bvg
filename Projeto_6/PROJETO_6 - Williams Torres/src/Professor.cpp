#include "Professor.h"
#include <sstream>

Professor::Professor(const std::string& nome, const std::string& senha, const std::string& departamento)
    : UsuarioAutenticavel(nome, senha), departamento(departamento) {}

bool Professor::autenticar(const std::string& senha) const {
    return this->senha == senha;
}

std::string Professor::gerarRelatorio() const {
    std::ostringstream oss;
    oss << "Relatório de Professor - Nome: " << nome << " - Departamento: " << departamento;
    return oss.str();
}
