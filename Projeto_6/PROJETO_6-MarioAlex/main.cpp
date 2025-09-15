#include <iostream>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdm.h"

int main() {
    // Criando usuários
    Aluno a1("Joao", "joao@email.com", "1234");
    a1.adicionarDisciplina("POO", 2024, 8.5);
    a1.adicionarDisciplina("Redes", 2025, 9.0);

    Professor p1("Maria", "maria@email.com", "abcd", "Banco de Dados");

    FuncionarioAdm f1("Carlos", "carlos@email.com", "senha", "Secretaria");

    // Teste de autenticação
    std::string senhaTentativa;
    std::cout << "Digite a senha do aluno Joao: ";
    std::cin >> senhaTentativa;

    if (a1.autenticar(senhaTentativa)) {
        std::cout << "Login realizado com sucesso!\n";
        a1.gerarRelatorio();
    } else {
        std::cout << "Senha incorreta.\n";
    }

    std::cout << "\n--- Relatorios do sistema ---\n";
    p1.gerarRelatorio();
    f1.gerarRelatorio();

    return 0;
}