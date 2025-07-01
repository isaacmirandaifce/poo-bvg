#include <iostream>
#include <vector>
#include <memory> // Para std::unique_ptr

#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Relatorio.h"

int main() {
    // --- 1. Criação dos Usuários ---
    auto aluno = std::make_unique<Aluno>(101, "Joao Silva", "senha123", "Analise e Des. de Sistemas");
    aluno->adicionarDisciplina("POO em C++", 2023, 9.5);
    aluno->adicionarDisciplina("Banco de Dados", 2023, 8.0);

    auto professor = std::make_unique<Professor>(202, "Dra. Ana Costa", "prof_segura", "Ciencia da Computacao");
    professor->adicionarDisciplina("Estrutura de Dados");
    professor->adicionarDisciplina("Inteligencia Artificial");

    auto funcionario = std::make_unique<FuncionarioAdministrativo>(303, "Carlos Pereira", "adm@sist", "Coordenador", "Secretaria Academica");

    // --- 2. Teste de Autenticação ---
    std::cout << "### Testando Autenticacao ###\n" << std::endl;
    
    // Tentativa correta
    if (aluno->autenticar("senha123")) {
        std::cout << "Sucesso! Acesso liberado." << std::endl;
    } else {
        std::cout << "Falha! Senha incorreta." << std::endl;
    }
    
    // Tentativa incorreta
    if (professor->autenticar("senha_errada")) {
        std::cout << "Sucesso! Acesso liberado." << std::endl;
    } else {
        std::cout << "Falha! Senha incorreta." << std::endl;
    }
    
    std::cout << "\n-----------------------------\n" << std::endl;


    // --- 3. Geração de Relatórios usando Polimorfismo ---
    std::cout << "### Gerando Relatorios ###\n" << std::endl;

    // Criamos um vetor de ponteiros para a INTERFACE Relatorio
    std::vector<const Relatorio*> relatorios;
    relatorios.push_back(aluno.get());
    relatorios.push_back(professor.get());
    relatorios.push_back(funcionario.get());

    // Iteramos e chamamos o mesmo método para objetos de tipos diferentes.
    // O C++ saberá qual versão de 'gerarRelatorio' chamar para cada objeto.
    for (const auto* rel : relatorios) {
        rel->gerarRelatorio();
    }

    return 0;
}