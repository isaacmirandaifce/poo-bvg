#include <iostream>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Filtro.h"

int main() {
    Aluno aluno1("Joao Silva", "12345", "Engenharia de Software", "senha123", 8.5);
    aluno1.adicionarDisciplinaAoHistorico("C++", 2023, 8.5f);
    aluno1.adicionarDisciplinaAoHistorico("Banco de Dados", 2023, 7.0f);

    Aluno aluno2("Maria Oliveira", "54321", "Ciencia da Computacao", "senha456", 6.5);
    aluno2.adicionarDisciplinaAoHistorico("Algoritmos", 2023, 9.0f);

    Professor professor1("Ana Costa", "C++", "senha789");
    Professor professor2("Pedro Santos", "Banco de Dados", "senha101");

    Filtro<Aluno> filtroAlunos;
    filtroAlunos.adicionarElemento(aluno1);
    filtroAlunos.adicionarElemento(aluno2);

    std::cout << "Alunos com media acima de 7.0:\n";
    auto alunosFiltrados = filtroAlunos.filtrarPorCondicao([](const Aluno& aluno) {
        return aluno.getMedia() > 7.0;
    });
    for (const auto& aluno : alunosFiltrados) {
        aluno.exibirInformacoes();
    }

    Filtro<Professor> filtroProfessores;
    filtroProfessores.adicionarElemento(professor1);
    filtroProfessores.adicionarElemento(professor2);

    std::cout << "\nProfessores que ministram C++:\n";
    auto professoresFiltrados = filtroProfessores.filtrarPorCondicao([](const Professor& professor) {
        return professor.getDisciplina() == "C++";
    });
    for (const auto& professor : professoresFiltrados) {
        professor.exibirInformacoes();
    }

    return 0;
}