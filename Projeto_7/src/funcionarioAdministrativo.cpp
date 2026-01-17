#include "FuncionarioAdministrativo.h"
#include <iostream>

FuncionarioAdministrativo::FuncionarioAdministrativo(
    const std::string& nome,
    const std::string& email,
    const std::string& senha,
    const std::string& setor)
    : UsuarioAutenticavel(nome, email, TipoUsuario::FUNCIONARIO_ADMINISTRATIVO, senha),
      setor(setor) {}

bool FuncionarioAdministrativo::autenticar(const std::string& senhaInformada) const {
    return senha == senhaInformada;
}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "Funcionário: " << nome
              << " | Setor: " << setor << std::endl;
}