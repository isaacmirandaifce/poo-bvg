#include <iostream>
#include "Filtro.h"
#include "Aluno.h"
#include "Professor.h"

int main() {
    Filtro<Aluno> filtroAlunos;
    Filtro<Professor> filtroProfessores;

    // Adicionando alunos ao filtro
    filtroAlunos.adicionarElemento(Aluno("João", 8.5, "Matemática"));
    filtroAlunos.adicionarElemento(Aluno("Maria", 6.7, "História"));
    filtroAlunos.adicionarElemento(Aluno("Carlos", 7.3, "Física"));

    // Adicionando professores ao filtro
    filtroProfessores.adicionarElemento(Professor("Dr. Silva", "Matemática"));
    filtroProfessores.adicionarElemento(Professor("Prof. Souza", "História"));

    // Filtrar alunos com média acima de 7.0
    auto aprovados = filtroAlunos.filtrarPorCondicao([](const Aluno& aluno) {
        return aluno.getMedia() > 7.0;
    });

    std::cout << "Alunos aprovados com média acima de 7.0:" << std::endl;
    for (const auto& aluno : aprovados) {
        aluno.imprimir();
    }

    // Ordenar alunos por média
    filtroAlunos.ordenarElementos([](const Aluno& a, const Aluno& b) {
        return a.getMedia() > b.getMedia();
    });

    std::cout << "\nAlunos ordenados por média (decrescente):" << std::endl;
    filtroAlunos.imprimirTodos([](const Aluno& aluno) {
        aluno.imprimir();
    });

    // Filtrar professores que ministram Matemática
    auto professoresMatematica = filtroProfessores.filtrarPorCondicao([](const Professor& professor) {
        return professor.getDisciplina() == "Matemática";
    });

    std::cout << "\nProfessores que ministram Matemática:" << std::endl;
    for (const auto& professor : professoresMatematica) {
        professor.imprimir();
    }

    return 0;
}
