#include "FuncionarioAdministrativo.h"
#include <iostream>
#include <sstream>

FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome, const std::string& email,
                                                     const std::string& matricula, const std::string& senha,
                                                     const std::string& cargo, const std::string& setor)
    : UsuarioAutenticavel(nome, email, matricula, TipoUsuario::FUNCIONARIO_ADMINISTRATIVO, senha),
      cargo(cargo), setor(setor) {}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "=== RELATÓRIO DO FUNCIONÁRIO ===" << std::endl;
    std::cout << "Nome: " << getNome() << std::endl;
    std::cout << "Matrícula: " << getMatricula() << std::endl;
    std::cout << "Cargo: " << cargo << std::endl;
    std::cout << "Setor: " << setor << std::endl;
    std::cout << "================================" << std::endl;
}

std::string FuncionarioAdministrativo::getCargo() const { return cargo; }
std::string FuncionarioAdministrativo::getSetor() const { return setor; }
void FuncionarioAdministrativo::setCargo(const std::string& cargo) { this->cargo = cargo; }
void FuncionarioAdministrativo::setSetor(const std::string& setor) { this->setor = setor; }

// Adições para o Projeto 7
std::ostream& operator<<(std::ostream& os, const FuncionarioAdministrativo& funcionario) {
    os << "Funcionário: " << funcionario.getNome()
       << " | Matrícula: " << funcionario.getMatricula()
       << " | Cargo: " << funcionario.getCargo()
       << " | Setor: " << funcionario.getSetor();
    return os;
}