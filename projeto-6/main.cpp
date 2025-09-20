#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"

int main() {
    // --- 1. Criação dos Objetos ---
    // Criando instâncias de cada tipo de usuário com suas senhas
    Aluno aluno1("Joao Silva", "joao@email.com", "senha123", "202301", "Analise e Des. de Sistemas");
    aluno1.adicionarDisciplinaAoHistorico("Programacao Orientada a Objetos", 2025, 9.5);
    aluno1.adicionarDisciplinaAoHistorico("Estrutura de Dados", 2024, 8.0);

    Professor prof1("Maria Souza", "maria@email.com", "prof@abc", "Inteligencia Artificial");
    prof1.adicionarDisciplina("Aprendizado de Maquina");

    FuncionarioAdministrativo func1("Carlos Pereira", "carlos@email.com", "adm#segredo", "Secretaria Academica", "Secretario");

    // --- 2. Demonstração da Autenticação ---
    std::cout << "--- TESTES DE AUTENTICACAO ---\n" << std::endl;

    // Criamos um vetor da classe base abstrata para testar a autenticação
    std::vector<UsuarioAutenticavel*> usuarios;
    usuarios.push_back(&aluno1);
    usuarios.push_back(&prof1);
    usuarios.push_back(&func1);

    for (UsuarioAutenticavel* u : usuarios) {
        // Teste com senha incorreta
        std::cout << "Tentando autenticar com senha errada ('senha_errada')... ";
        if (u->autenticar("senha_errada")) {
            std::cout << "Sucesso! (Inesperado)" << std::endl;
        } else {
            std::cout << "Falhou! (Esperado)" << std::endl;
        }

        // Teste com senha correta
        std::cout << "Tentando autenticar com a senha correta... ";
        if (u->autenticar( (u == &aluno1) ? "senha123" : (u == &prof1) ? "prof@abc" : "adm#segredo" )) {
            std::cout << "Sucesso! (Esperado)" << std::endl;
        } else {
            std::cout << "Falhou! (Inesperado)" << std::endl;
        }
        std::cout << "------------------------------------\n" << std::endl;
    }

    // --- 3. Demonstração dos Relatórios Polimórficos ---
    std::cout << "\n--- GERANDO RELATORIOS POLIMORFICOS ---\n" << std::endl;

    // Criamos um vetor da interface para testar os relatórios
    std::vector<Relatorio*> relatorios;
    relatorios.push_back(&aluno1);
    relatorios.push_back(&prof1);
    relatorios.push_back(&func1);

    for (Relatorio* r : relatorios) {
        r->gerarRelatorio();
        std::cout << "====================================\n" << std::endl;
    }

    return 0;
}
