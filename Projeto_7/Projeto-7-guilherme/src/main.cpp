#include <iostream>
#include "Filtro.h"
#include "aluno.h"
#include "Professor.h"

int main() {
    // Criando alunos
    Aluno a1("Guilherme", "guilherme.12@gmail.com", "123", "2023001", "ADS");
    a1.adicionarDisciplinaHistorico("POO", 2024, 8.5);
    a1.adicionarDisciplinaHistorico("IHC", 2024, 6.0);
    a1.adicionarDisciplinaHistorico("Banco de Dados", 2023, 7.2);

    Aluno a2("Carlos", "carlos@gmail.com", "456", "2023002", "SI");
    a2.adicionarDisciplinaHistorico("POO", 2024, 6.9);
    a2.adicionarDisciplinaHistorico("Redes", 2023, 7.5);

    // Criando professores
    Professor p1("Isaac", "Isaac.miranda@ifce.edu.br", "Computação");
    p1.adicionarDisciplina("POO");
    p1.adicionarDisciplina("IHC");

    Professor p2("Fernanda", "fernandalara.josearmando@gmail.com", "Informática");
    p2.adicionarDisciplina("Redes");
    p2.adicionarDisciplina("Banco de Dados");

    // === FILTRO DE ALUNOS COM MÉDIA > 7 ===
    Filtro<Aluno> filtroAlunos;
    filtroAlunos.adicionarElemento(a1);
    filtroAlunos.adicionarElemento(a2);

    std::cout << "\n--- Alunos com média geral acima de 7 ---\n";
    auto alunosAcimaMedia = filtroAlunos.filtrarPorCondicao([](const Aluno& a) {
        // Calcula média
        float soma = 0.0f;
        int count = 0;
        a.executarNoHistorico([&](const std::string&, int, float nota) {
            soma += nota;
            count++;
        });
        float media = (count > 0) ? soma / count : 0.0f;
        return media > 7.0f;
    });

    for (const auto& aluno : alunosAcimaMedia) {
        aluno.exibirInformacoes(true);
        std::cout << "\n";
    }

    // === FILTRO DE DISCIPLINAS DE UM ALUNO EM UM ANO ===
    std::cout << "\n--- Disciplinas cursadas por Guilherme em 2024 ---\n";
    a1.executarNoHistorico([](const std::string& nome, int ano, float nota) {
        if (ano == 2024) {
            std::cout << nome << " | Nota: " << nota << "\n";
        }
    });

    // === FILTRO DE PROFESSORES POR DISCIPLINA ===
    Filtro<Professor> filtroProfessores;
    filtroProfessores.adicionarElemento(p1);
    filtroProfessores.adicionarElemento(p2);

    std::string disciplinaBuscada = "POO";
    std::cout << "\n--- Professores que ministram " << disciplinaBuscada << " ---\n";
    auto profsFiltrados = filtroProfessores.filtrarPorCondicao([&](const Professor& p) {
        return p.ministraDisciplina(disciplinaBuscada);
    });

    for (const auto& prof : profsFiltrados) {
        prof.gerarRelatorio();
        std::cout << "\n";
    }

    return 0;
}
