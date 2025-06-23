#include "FuncionarioAdministrativo.h"

FuncionarioAdministrativo::FuncionarioAdministrativo(std::string nome, std::string cpf, std::string senha, std::string cargo)
    : UsuarioAutenticavel(nome, cpf, TipoUsuario::FUNCIONARIO_ADMINISTRATIVO, senha), cargo(cargo) {}


bool FuncionarioAdministrativo::autenticar(const std::string& senhaFornecida) const {
    return this->senha == senhaFornecida;
}

std::string FuncionarioAdministrativo::gerarRelatorio() const {
    std::stringstream ss;
    ss << "===== Relatório do Funcionário Administrativo =====\n";
    ss << "Nome: " << nome << "\n";
    ss << "CPF: " << cpf << "\n";
    ss << "Cargo: " << cargo << "\n";
    ss << "==================================================\n";
    return ss.str();
}