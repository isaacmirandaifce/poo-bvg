#include <iostream>
#include "Filtro.h"
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"

int main() {
    // ===================== Alunos =====================
    Filtro<Aluno> filtroAlunos;
    filtroAlunos.adicionarElemento(Aluno("Carlos", 8.5, 2022));
    filtroAlunos.adicionarElemento(Aluno("Ana", 6.9, 2021));
    filtroAlunos.adicionarElemento(Aluno("Marcos", 7.8, 2023));

    std::cout << "\nAlunos com média > 7.0:\n";
    auto aprovados = filtroAlunos.filtrarPorCondicao([](const Aluno& a) {
        return a.getMedia() > 7.0;
    });
    aprovados.imprimirTodos([](const Aluno& a) { a.imprimir(); });

    // Ordenar por nome
    std::cout << "\nAlunos ordenados por nome:\n";
    filtroAlunos.ordenar([](const Aluno& a1, const Aluno& a2) {
        return a1.getNome() < a2.getNome();
    });
    filtroAlunos.imprimirTodos([](const Aluno& a) { a.imprimir(); });

    // ===================== Professores =====================
    Filtro<Professor> filtroProf;
    filtroProf.adicionarElemento(Professor("João", "Matemática"));
    filtroProf.adicionarElemento(Professor("Maria", "História"));
    filtroProf.adicionarElemento(Professor("Pedro", "Matemática"));

    std::cout << "\nProfessores que ministram Matemática:\n";
    auto matematicos = filtroProf.filtrarPorCondicao([](const Professor& p) {
        return p.getDisciplina() == "Matemática";
    });
    matematicos.imprimirTodos([](const Professor& p) { p.imprimir(); });

    // ===================== Disciplinas =====================
    Filtro<Disciplina> filtroDisc;
    filtroDisc.adicionarElemento(Disciplina("POO", 2023));
    filtroDisc.adicionarElemento(Disciplina("BD", 2022));
    filtroDisc.adicionarElemento(Disciplina("IHC", 2023));

    std::cout << "\nDisciplinas cursadas em 2023:\n";
    auto disc2023 = filtroDisc.filtrarPorCondicao([](const Disciplina& d) {
        return d.getAno() == 2023;
    });
    disc2023.imprimirTodos([](const Disciplina& d) { d.imprimir(); });

    return 0;
}
