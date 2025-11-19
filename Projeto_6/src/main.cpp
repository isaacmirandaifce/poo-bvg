#include <iostream>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Disciplina.h"

int main() {
    // Criando um aluno
    Aluno a("Maria Silva", "maria@exemplo.com", "2023001", "Sistemas");
    a.setSenha("senha123");
    a.adicionarHistorico("Programacao I", 2022, 8.5f);
    a.adicionarHistorico("Matematica Discreta", 2022, 7.0f);
    Disciplina d1("Algoritmos", 60, 8.0f);
    a.adicionarDisciplina(d1);

    // Criando um professor
    Professor p("Joao Souza", "joao@exemplo.com", "Computacao");
    p.setSenha("profSenha");
    p.adicionarDisciplinaMinistrada("Algoritmos");

    // Criando um funcionario
    FuncionarioAdministrativo f("Ana Pereira", "ana@exemplo.com", "Secretaria", "Atendimento");
    f.setSenha("func123");

    // Autenticacao e relatorios
    std::string tentativa;

    tentativa = "senha123";
    std::cout << "Autenticando Maria com '" << tentativa << "': " << (a.autenticar(tentativa) ? "OK" : "Falha") << std::endl;

    tentativa = "errada";
    std::cout << "Autenticando Joao com '" << tentativa << "': " << (p.autenticar(tentativa) ? "OK" : "Falha") << std::endl;

    std::cout << std::endl << "Relatorios:" << std::endl;
    a.gerarRelatorio();
    std::cout << std::endl;
    p.gerarRelatorio();
    std::cout << std::endl;
    f.gerarRelatorio();

    return 0;
}
