#include "Aluno.h"
#include <iostream>

int main() {
    Aluno aluno("Carlos", "carlos@example.com", "2023001", "Engenharia", 8.5);

    std::cout << "Teste de autenticação do Aluno:\n";
    std::cout << "Senha correta (12345): " << (aluno.autenticar("12345") ? "Sucesso" : "Falha") << "\n";
    std::cout << "Senha incorreta (abc123): " << (aluno.autenticar("abc123") ? "Sucesso" : "Falha") << "\n";

    std::cout << "\nRelatório do Aluno:\n";
    aluno.gerarRelatorio();

    return 0;
}