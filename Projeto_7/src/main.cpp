#include "Aluno.h"
#include "Professor.h"
#include "Filtro.h"
#include <iostream>

int main() {
    Filtro<Aluno> filtroAlunos;

    filtroAlunos.adicionarElemento(
        Aluno("Aluno1", "aluno1@ifce.edu.br", "123", 8.5));
    filtroAlunos.adicionarElemento(
        Aluno("Aluno2", "aluno2@ifce.edu.br", "123", 6.0));

    auto aprovados = filtroAlunos.filtrarPorCondicao(
        [](const Aluno& a) {
            return a.getMedia() > 7.0;
        });

    for (const auto& a : aprovados) {
        a.gerarRelatorio();
    }

    return 0;
}