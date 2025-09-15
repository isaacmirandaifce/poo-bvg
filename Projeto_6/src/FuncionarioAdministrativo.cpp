#include "FuncionarioAdministrativo.h"
#include <iostream>
#include <iomanip>

FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome, const std::string& email,
                                                   int id, const std::string& senha, const std::string& setor,
                                                   const std::string& cargo, double salario)
    : UsuarioAutenticavel(nome, email, id, TipoUsuario::FUNCIONARIO_ADMINISTRATIVO, senha),
      setor(setor), cargo(cargo), salario(salario) {}

std::string FuncionarioAdministrativo::getSetor() const { return setor; }
std::string FuncionarioAdministrativo::getCargo() const { return cargo; }
double FuncionarioAdministrativo::getSalario() const { return salario; }
void FuncionarioAdministrativo::setSetor(const std::string& setor) { this->setor = setor; }
void FuncionarioAdministrativo::setCargo(const std::string& cargo) { this->cargo = cargo; }
void FuncionarioAdministrativo::setSalario(double salario) { this->salario = salario; }

bool FuncionarioAdministrativo::autenticar(const std::string& senha) {
    return gerarHash(senha) == senhaHash;
}

void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "\n=== RELATÓRIO DO FUNCIONÁRIO ===" << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Setor: " << setor << std::endl;
    std::cout << "Cargo: " << cargo << std::endl;
    std::cout << "Salário: R$ " << std::fixed << std::setprecision(2) << salario << std::endl;
    std::cout << "================================" << std::endl;
}

void FuncionarioAdministrativo::exibirInformacoes() const {
    Usuario::exibirInformacoes();
    std::cout << "Setor: " << setor << "\nCargo: " << cargo << std::endl;
}
