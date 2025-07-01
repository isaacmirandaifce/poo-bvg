#include "FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo(int id, std::string nome, std::string senha, std::string cargo, std::string setor)
    : UsuarioAutenticavel(id, nome, TipoUsuario::FUNCIONARIO_ADMINISTRATIVO, senha), cargo(cargo), setor(setor) {}

bool FuncionarioAdministrativo::autenticar(const std::string& senha) const {
    std::cout << "Autenticando funcionario '" << this->nome << "'... ";
    return verificarSenha(senha);
}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "\n--- Relatorio do Funcionario Administrativo ---" << std::endl;
    std::cout << "ID: " << this->id << std::endl;
    std::cout << "Nome: " << this->nome << std::endl;
    std::cout << "Tipo: " << this->getTipoAsString() << std::endl;
    std::cout << "Cargo: " << this->cargo << std::endl;
    std::cout << "Setor: " << this->setor << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
}