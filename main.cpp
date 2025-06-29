#include <iostream>
#include "Filtro.h"
#include "Aluno.h"
#include "Professor.h"

int main() {
    Filtro<Aluno> filtroAlunos;
    Filtro<Professor> filtroProfessores;

    // Criando disciplinas
    Disciplina mat("Matemática", 2023);
    Disciplina port("Português", 2023);

    // Criando alunos
    Aluno joao("João", 8.5, 2023);
    joao.adicionarDisciplina(mat);
    joao.adicionarDisciplina(port);

    Aluno maria("Maria", 6.7, 2022);
    maria.adicionarDisciplina(port);

    Aluno carlos("Carlos", 7.2, 2023);
    carlos.adicionarDisciplina(mat);

    filtroAlunos.adicionarElemento(joao);
    filtroAlunos.adicionarElemento(maria);
    filtroAlunos.adicionarElemento(carlos);

    // Criando professores
    Professor prof1("Ana");
    prof1.adicionarDisciplina("Matemática");

    Professor prof2("Bruno");
    prof2.adicionarDisciplina("Português");

    filtroProfessores.adicionarElemento(prof1);
    filtroProfessores.adicionarElemento(prof2);

    // Filtrar alunos com média > 7
    std::cout << "\nAlunos com média acima de 7.0:\n";
    auto aprovados = filtroAlunos.filtrarPorCondicao([](const Aluno& a) {
        return a.getMedia() > 7.0;
    });
    for (const auto& aluno : aprovados) {
        aluno.imprimir();
    }

    // Professores que lecionam Matemática
    std::cout << "\nProfessores que lecionam Matemática:\n";
    auto matProfs = filtroProfessores.filtrarPorCondicao([](const Professor& p) {
        for (const auto& d : p.getDisciplinas()) {
            if (d == "Matemática") return true;
        }
        return false;
    });
    for (const auto& p : matProfs) {
        p.imprimir();
    }

    // Disciplinas de alunos do ano 2023
    std::cout << "\nDisciplinas cursadas por alunos em 2023:\n";
    auto alunos2023 = filtroAlunos.filtrarPorCondicao([](const Aluno& a) {
        return a.getAno() == 2023;
    });
    for (const auto& aluno : alunos2023) {
        aluno.imprimir();
    }

    // Ordenar alunos por nome
    std::cout << "\nAlunos ordenados por nome:\n";
    filtroAlunos.ordenarPor([](const Aluno& a, const Aluno& b) {
        return a.getNome() < b.getNome();
    });
    filtroAlunos.imprimirTodos([](const Aluno& a) {
        a.imprimir();
    });

    return 0;
}
