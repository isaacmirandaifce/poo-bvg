#include <iostream>
#include <cassert>
#include "../src/headers/Aluno.h"
#include "../src/headers/Professor.h"
#include "../src/headers/FuncionarioAdministrativo.h"
#include "../src/headers/SistemaAcademico.h"

void test_aluno() {
    std::cout << "Testando classe Aluno..." << std::endl;
    
    Aluno aluno("Teste Aluno", "teste@email.com", "TEST001", "senha123", "ADS");
    
    assert(aluno.getNome() == "Teste Aluno");
    assert(aluno.getMatricula() == "TEST001");
    assert(aluno.getCurso() == "ADS");
    assert(aluno.autenticar("senha123"));
    assert(!aluno.autenticar("senhaerrada"));
    
    aluno.adicionarDisciplina("Matemática", 2023, 9.5);
    aluno.adicionarDisciplina("Física", 2023, 8.0);
    
    assert(aluno.calcularMedia() == 8.75);
    
    std::cout << "Testes de Aluno passaram!" << std::endl;
}

void test_professor() {
    std::cout << "Testando classe Professor..." << std::endl;
    
    Professor prof("Teste Prof", "prof@email.com", "PROF_TEST", "prof123", "Exatas");
    
    assert(prof.getNome() == "Teste Prof");
    assert(prof.getDepartamento() == "Exatas");
    assert(prof.autenticar("prof123"));
    
    prof.adicionarDisciplina("Matemática");
    prof.adicionarDisciplina("Física");
    
    std::cout << "Testes de Professor passaram!" << std::endl;
}

void test_funcionario() {
    std::cout << "Testando classe Funcionario..." << std::endl;
    
    FuncionarioAdministrativo func("Teste Func", "func@email.com", 
                                  "FUNC_TEST", "func123", "Assistente", "Administrativo");
    
    assert(func.getNome() == "Teste Func");
    assert(func.getCargo() == "Assistente");
    assert(func.getSetor() == "Administrativo");
    assert(func.autenticar("func123"));
    
    std::cout << "Testes de Funcionario passaram!" << std::endl;
}

void test_sistema() {
    std::cout << "Testando Sistema Acadêmico..." << std::endl;
    
    SistemaAcademico sistema;
    
    auto aluno = std::make_shared<Aluno>("Aluno Test", "aluno@test.com", 
                                        "ALU_TEST", "aluno123", "TI");
    auto professor = std::make_shared<Professor>("Prof Test", "prof@test.com",
                                                "PROF_TEST", "prof123", "Tecnologia");
    
    sistema.adicionarUsuario(aluno);
    sistema.adicionarUsuario(professor);
    
    assert(sistema.autenticarUsuario("ALU_TEST", "aluno123"));
    assert(sistema.autenticarUsuario("PROF_TEST", "prof123"));
    assert(!sistema.autenticarUsuario("ALU_TEST", "senhaerrada"));
    
    std::cout << "Testes de Sistema passaram!" << std::endl;
}

int main() {
    std::cout << "Iniciando testes..." << std::endl;
    
    test_aluno();
    test_professor();
    test_funcionario();
    test_sistema();
    
    std::cout << "\nTodos os testes passaram com sucesso!" << std::endl;
    return 0;
}