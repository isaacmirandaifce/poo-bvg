#include <iostream>
#include <memory>
#include "headers/SistemaAcademico.h"
#include "headers/Aluno.h"
#include "headers/Professor.h"
#include "headers/FuncionarioAdministrativo.h"

int main() {
    SistemaAcademico sistema;
    
    auto aluno1 = std::make_shared<Aluno>("João Silva", "joao@email.com", 
                                         "2023001", "senha123", "ADS");
    aluno1->adicionarDisciplina("Programação OO", 2023, 8.5);
    aluno1->adicionarDisciplina("Banco de Dados", 2023, 9.0);
    
    auto professor1 = std::make_shared<Professor>("Maria Santos", "maria@email.com",
                                                 "PROF001", "prof123", "Tecnologia");
    professor1->adicionarDisciplina("Programação OO");
    professor1->adicionarDisciplina("Estrutura de Dados");
    
    auto funcionario1 = std::make_shared<FuncionarioAdministrativo>("Carlos Oliveira", 
                                                                   "carlos@email.com",
                                                                   "FUNC001", "admin123",
                                                                   "Coordenador", "Acadêmico");
    
    sistema.adicionarUsuario(aluno1);
    sistema.adicionarUsuario(professor1);
    sistema.adicionarUsuario(funcionario1);
    
    std::cout << "Teste de autenticação:" << std::endl;
    std::cout << "Aluno 2023001: " << (sistema.autenticarUsuario("2023001", "senha123") ? "OK" : "Falha") << std::endl;
    std::cout << "Professor PROF001: " << (sistema.autenticarUsuario("PROF001", "prof123") ? "OK" : "Falha") << std::endl;
    std::cout << "Senha incorreta: " << (sistema.autenticarUsuario("2023001", "errada") ? "OK" : "Falha") << std::endl;
    
    std::cout << "\n";
    
    sistema.listarUsuarios();
    
    std::cout << "\n";
    
    sistema.gerarRelatorios();
    
    return 0;
}