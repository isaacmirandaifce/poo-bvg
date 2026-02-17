#include "FuncionarioAdministrativo.h"

FuncionarioAdministrativo::FuncionarioAdministrativo(std::string nome, std::string email, std::string senha, std::string setor)
    : UsuarioAutenticavel(nome, email, TipoUsuario::FUNCIONARIO_ADMINISTRATIVO, senha), setor(setor) {}

bool FuncionarioAdministrativo::autenticar(std::string senha) const {
    return this->senha == senha;
}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "Relatorio do Funcionario Administrativo\n";
    std::cout << "Nome: " << nome << "\nEmail: " << email << "\n";
    std::cout << "Setor: " << setor << "\n";
}
