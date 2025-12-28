#include <iostream>
#include "Filtro.h"
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"

int main() {
    Filtro<Aluno> filtroAlunos;
    filtroAlunos.adicionarElemento(Aluno("Carlos", 8.5, 2023));
    filtroAlunos.adicionarElemento(Aluno("Ana", 6.8, 2023));
    filtroAlunos.adicionarElemento(Aluno("Bruno", 7.4, 2022));

    auto alunosAprovados = filtroAlunos.filtrarPorCondicao(
        [](const Aluno& a) { return a.getMedia() > 7.0; }
    );

    for (const auto& a : alunosAprovados) {
        std::cout << a.getNome() << " - Media: " << a.getMedia() << std::endl;
    }

    filtroAlunos.ordenar(
        [](const Aluno& a1, const Aluno& a2) {
            return a1.getNome() < a2.getNome();
        }
    );

    Filtro<Professor> filtroProfessores;
    filtroProfessores.adicionarElemento(Professor("Marcos", "POO"));
    filtroProfessores.adicionarElemento(Professor("Juliana", "Estrutura de Dados"));

    auto professoresPOO = filtroProfessores.filtrarPorCondicao(
        [](const Professor& p) {
            return p.getDisciplina() == "POO";
        }
    );

    for (const auto& p : professoresPOO) {
        std::cout << p.getNome() << std::endl;
    }

    Filtro<Disciplina> filtroDisciplinas;
    filtroDisciplinas.adicionarElemento(Disciplina("POO", 2023));
    filtroDisciplinas.adicionarElemento(Disciplina("Banco de Dados", 2022));

    auto disciplinas2023 = filtroDisciplinas.filtrarPorCondicao(
        [](const Disciplina& d) {
            return d.getAno() == 2023;
        }
    );

    for (const auto& d : disciplinas2023) {
        std::cout << d.getNome() << std::endl;
    }

    return 0;
}
