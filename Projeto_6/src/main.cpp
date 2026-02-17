#include <iostream>
#include <vector>

#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "UsuarioAutenticavel.h"

int main() {
    Aluno a("Joao Paulo", "joaopaulo@email.com", "123");
    Professor p("Talita", "talita@email.com", "abc", "TI");
    FuncionarioAdministrativo f("Beatriz", "beatriz@email.com", "999", "Secretaria");

    std::cout << "=== Testes de autenticação ===\n";
    std::cout << "Aluno (123): " << (a.autenticar("123") ? "OK" : "Falhou") << "\n";
    std::cout << "Aluno (000): " << (a.autenticar("000") ? "OK" : "Falhou") << "\n\n";

    std::cout << "Professor (abc): " << (p.autenticar("abc") ? "OK" : "Falhou") << "\n";
    std::cout << "Professor (123): " << (p.autenticar("123") ? "OK" : "Falhou") << "\n\n";

    std::cout << "Func. Admin (999): " << (f.autenticar("999") ? "OK" : "Falhou") << "\n";
    std::cout << "Func. Admin (111): " << (f.autenticar("111") ? "OK" : "Falhou") << "\n\n";

    std::cout << "=== Relatório do aluno sem disciplinas ===\n";
    a.gerarRelatorio();
    std::cout << "\n\n";

    a.adicionarDisciplina("POO", 2024, 9.5f);
    a.adicionarDisciplina("Banco de Dados", 2024, 8.8f);

    std::cout << "=== Relatório do aluno com disciplinas ===\n";
    a.gerarRelatorio();
    std::cout << "\n\n";

    std::cout << "=== Relatórios (professor e funcionário) ===\n";
    p.gerarRelatorio();
    std::cout << "\n\n";
    f.gerarRelatorio();
    std::cout << "\n\n";

    std::cout << "=== Teste UsuarioAutenticavel (polimorfismo) ===\n";
std::vector<UsuarioAutenticavel*> usuarios = { &a, &p, &f };
std::vector<std::string> tentativas = { "123", "abc", "999" };

for (size_t i = 0; i < usuarios.size(); i++) {
    auto* u = usuarios[i];
    std::cout << u->getNome() << " -> senha correta: "
              << (u->autenticar(tentativas[i]) ? "OK" : "Falhou") << "\n";
}

    return 0;
}
