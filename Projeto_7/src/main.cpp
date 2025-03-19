#include <iostream>
#include <string>
#include "Filtro.h"
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Disciplina.h"

int main() {
    Filtro<Aluno> filtroAlunos;
    filtroAlunos.adicionarElemento(Aluno("João", 8.5));
    filtroAlunos.adicionarElemento(Aluno("Maria", 6.5));
    filtroAlunos.adicionarElemento(Aluno("Pedro", 7.5));

    auto alunosAprovados = filtroAlunos.filtrarPorCondicao([](const Aluno& aluno) {
        return aluno.getMedia() >= 7.0;
    });

    std::cout << "Alunos com média >= 7.0:\n";
    for (const auto& aluno : alunosAprovados) {
        std::cout << aluno.getNome() << " - Média: " << aluno.getMedia() << "\n";
    }

    Filtro<Professor> filtroProfessores;
    filtroProfessores.adicionarElemento(Professor("Carlos", "Matemática"));
    filtroProfessores.adicionarElemento(Professor("Ana", "História"));

    auto professoresMatematica = filtroProfessores.filtrarPorCondicao([](const Professor& professor) {
        return professor.getDisciplina() == "Matemática";
    });

    std::cout << "\nProfessores de Matemática:\n";
    for (const auto& professor : professoresMatematica) {
        std::cout << professor.getNome() << " - Disciplina: " << professor.getDisciplina() << "\n";
    }

    return 0;
}