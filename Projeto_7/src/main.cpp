#include <iostream>
#include <string>

#include "Filtro.h"
#include "Aluno.h"
#include "Professor.h"

int main() {
    
    Aluno a1("Joao Paulo", "joaopaulo@email.com", "123");
    a1.adicionarDisciplina("POO", 2024, 9.5f);
    a1.adicionarDisciplina("BD", 2024, 8.0f);
    a1.adicionarDisciplina("ED", 2023, 7.0f);

    Aluno a2("Jhone", "jhone@email.com", "999");
    a2.adicionarDisciplina("POO", 2024, 6.0f);
    a2.adicionarDisciplina("BD", 2024, 6.5f);

    Aluno a3("David", "david@email.com", "abc");
    a3.adicionarDisciplina("POO", 2024, 8.2f);
    a3.adicionarDisciplina("Redes", 2024, 7.8f);

    Professor p1("Isaac", "isaac@email.com", "senha1", "TI");
    p1.adicionarDisciplinaMinistrada("POO");
    p1.adicionarDisciplinaMinistrada("IHC");

    Professor p2("Renato", "renato@email.com", "senha2", "Computacao");
    p2.adicionarDisciplinaMinistrada("Redes");
    //Teste de autenticação
    std::cout << "=== Teste rapido de autenticação ===\n";
    std::cout << "Login aluno (123): " << (a1.autenticar("123") ? "OK" : "Falhou") << "\n\n";

    std::cout << "=== Relatorio básico do aluno ===\n";
    a1.gerarRelatorio();
    std::cout << "\n\n";

    // ===== 1) Alunos com média > 7.0 =====
    Filtro<Aluno> filtroAlunos;
    filtroAlunos.adicionarElemento(a1);
    filtroAlunos.adicionarElemento(a2);
    filtroAlunos.adicionarElemento(a3);

    auto alunosAcimaDe7 = filtroAlunos.filtrarPorCondicao([](const Aluno& a) {
        return a.calcularMedia() > 7.0f;
    });

    std::cout << "=== Alunos com media > 7.0 ===\n";
    for (const auto& a : alunosAcimaDe7) {
        std::cout << "- " << a.getNome() << " | media: " << a.calcularMedia() << "\n";
    }
    std::cout << "\n";

    // =====  Professores que ministram disciplina específica =====
    Filtro<Professor> filtroProf;
    filtroProf.adicionarElemento(p1);
    filtroProf.adicionarElemento(p2);

    std::string disciplinaAlvo = "POO";
    auto profsDaDisciplina = filtroProf.filtrarPorCondicao([&](const Professor& p) {
        return p.ministra(disciplinaAlvo);
    });

    std::cout << "=== Professores que ministram " << disciplinaAlvo << " ===\n";
    for (const auto& p : profsDaDisciplina) {
        std::cout << "- " << p.getNome() << "\n";
    }
    std::cout << "\n";

    // =====  Disciplinas cursadas por um aluno em um ano =====
    int anoAlvo = 2024;
    Filtro<Aluno::HistoricoDisciplinar> filtroHistorico;

    for (const auto& h : a1.getHistorico()) {
        filtroHistorico.adicionarElemento(h);
    }

    auto disciplinasDoAno = filtroHistorico.filtrarPorCondicao([&](const Aluno::HistoricoDisciplinar& h) {
        return h.getAno() == anoAlvo;
    });

    std::cout << "=== Disciplinas cursadas por " << a1.getNome() << " em " << anoAlvo << " ===\n";
    for (const auto& h : disciplinasDoAno) {
        std::cout << "- " << h.getDisciplina() << " | nota: " << h.getNota() << "\n";
    }
    std::cout << "\n";

    // ===== Ordenação genérica (ex.: por nome) =====
    filtroAlunos.ordenar([](const Aluno& a, const Aluno& b) {
        return a.getNome() < b.getNome();
    });

    std::cout << "=== Alunos ordenados por nome ===\n";
    filtroAlunos.imprimirTodos([](const Aluno& a) {
        std::cout << "- " << a.getNome() << " | media: " << a.calcularMedia() << "\n";
    });

    std::cout << "\n";

    // ===== Ordenação genérica (ex.: por média desc) =====
    filtroAlunos.ordenar([](const Aluno& a, const Aluno& b) {
        return a.calcularMedia() > b.calcularMedia();
    });

    std::cout << "=== Alunos ordenados por media (desc) ===\n";
    filtroAlunos.imprimirTodos([](const Aluno& a) {
        std::cout << "- " << a.getNome() << " | media: " << a.calcularMedia() << "\n";
    });

    return 0;
}
