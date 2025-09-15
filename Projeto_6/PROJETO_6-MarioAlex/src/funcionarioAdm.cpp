#include "funcionarioAdm.h"
#include <iostream>

FuncionarioAdm::FuncionarioAdm(std::string nome, std::string email, std::string senha, std::string setor)
    : UsuarioAutenticavel(nome, email, TipoUsuario::FUNCIONARIO_ADMINISTRATIVO, senha),
      setor(setor) {}

bool FuncionarioAdm::autenticar(std::string senhaDigitada) const {
    return senhaDigitada == senha; // "senha" vem da classe base
}

void FuncionarioAdm::gerarRelatorio() const {
    std::cout << "Relatorio do Funcionario Administrativo: " << nome << "\n";
    std::cout << "Setor: " << setor << "\n";
}