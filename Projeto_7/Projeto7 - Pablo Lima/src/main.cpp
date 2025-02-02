#include <iostream>
#include "Filtro.h"
#include "Aluno.h"
#include "Professor.h"

int main() {
    Filtro<Aluno> filtroAlunos;
    filtroAlunos.adicionarElemento(Aluno("João Silva", "joao@email.com", "12345", "Engenharia", 8.5));
    filtroAlunos.adicionarElemento(Aluno("Maria Oliveira", "maria@email.com", "67890", "Matemática", 6.0));
    filtroAlunos.adicionarElemento(Aluno("Carlos Souza", "carlos@email.com", "54321", "Física", 9.2));

    std::cout << "Alunos com média acima de 7.0:\n";
    auto alunosAprovados = filtroAlunos.filtrarPorCondicao([](const Aluno& a) { return a.getMedia() > 7.0; });
    for (const auto& aluno : alunosAprovados) {
        aluno.gerarRelatorio();
    }

    return 0;
}
