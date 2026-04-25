#include "Professor.h"

Professor::Professor(std::string nome, std::string email, std::string senha, std::string departamento)
    : UsuarioAutenticavel(nome, email, TipoUsuario::PROFESSOR, senha), departamento(departamento) {}

bool Professor::autenticar(std::string senha) const {
    return this->senha == senha;
}

void Professor::gerarRelatorio() const {
    std::cout << "Relatorio do Professor\n";
    std::cout << "Nome: " << nome << "\nEmail: " << email << "\n";
    std::cout << "Departamento: " << departamento << "\n";
}
