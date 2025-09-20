#include "FuncionarioAdministrativo.h"
#include <iostream>

// Implementação do construtor
FuncionarioAdministrativo::FuncionarioAdministrativo(std::string nome, std::string email, std::string senha, std::string departamento, std::string cargo)
    // Chama o construtor da classe mãe (UsuarioAutenticavel)
    : UsuarioAutenticavel(nome, email, TipoUsuario::FUNCIONARIO_ADMINISTRATIVO, senha), departamento(departamento), cargo(cargo) {
}

// Implementação do método de autenticação
bool FuncionarioAdministrativo::autenticar(const std::string& senha) {
    // A lógica é a mesma das outras classes: compara a senha fornecida com a armazenada
    return this->getSenha() == senha;
}

// Implementação do método de relatório
void FuncionarioAdministrativo::gerarRelatorio() {
    std::cout << "--- Relatorio Funcional ---" << std::endl;
    std::cout << "Nome: " << this->nome << std::endl;
    std::cout << "Departamento: " << this->departamento << std::endl;
    std::cout << "Cargo: " << this->cargo << std::endl;
}
