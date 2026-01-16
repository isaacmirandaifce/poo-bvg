#include <iostream>
#include "Filtro.h"
#include "Aluno.h"
#include "Professor.h"

int main() {
    Aluno a1("João", "joao@email.com", "A01", "Engenharia");
    a1.adicionarHistorico("Programação", 2024, 8.5f);
    a1.adicionarHistorico("Matemática", 2024, 7.0f);

    Aluno a2("Maria", "maria@email.com", "A02", "Direito");
    a2.adicionarHistorico("Filosofia", 2023, 5.0f);

    Filtro<Aluno> filtroAlunos;
    filtroAlunos.adicionar(a1);
    filtroAlunos.adicionar(a2);

    std::cout << "Alunos com média acima de 7:\n";
    auto aprovados = filtroAlunos.filtrar([](const Aluno& a) {
        float soma = 0;
        for (const auto& h : a.getHistorico()) soma += h.getNota();
        return !a.getHistorico().empty() &&
               (soma / a.getHistorico().size()) > 7.0f;
    });

    for (const auto& a : aprovados)
        std::cout << "- " << a.getNome() << "\n";

    return 0;
}
