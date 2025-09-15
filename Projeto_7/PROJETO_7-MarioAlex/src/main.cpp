#include <iostream>
#include "Filtro.h"
#include "Aluno.h"
#include "Professor.h"
#include "funcionarioAdm.h"

int main() {
    Filtro<Aluno> filtroAlunos;
    Filtro<Professor> filtroProfessores;

    // Criando alunos
    Aluno a1("Joao", "joao@email.com", "1234");
    a1.adicionarDisciplina("POO", 2024, 8.5);
    a1.adicionarDisciplina("Redes", 2025, 9.0);

    Aluno a2("Ana", "ana@email.com", "5678");
    a2.adicionarDisciplina("POO", 2024, 6.0);
    a2.adicionarDisciplina("Redes", 2025, 7.5);

    // Criando professores
    Professor p1("Maria", "maria@email.com", "abcd", "Banco de Dados");
    Professor p2("Pedro", "pedro@email.com", "xyz", "Redes");

    // Adiciona ao filtro
    filtroAlunos.adicionarElemento(a1);
    filtroAlunos.adicionarElemento(a2);
    filtroProfessores.adicionarElemento(p1);
    filtroProfessores.adicionarElemento(p2);

    // Filtra alunos com média >= 7
    std::cout << "--- Alunos com média >= 7 ---\n";
    auto alunosFiltrados = filtroAlunos.filtrarPorCondicao([](const Aluno& a){
        float soma = 0;
        int count = 0;
        for (const auto& h : a.getHistorico()) { // precisa existir
            soma += h.nota;
            count++;
        }
        return (count > 0) && ((soma/count) >= 7.0);
    });
    for (const auto& aluno : alunosFiltrados) std::cout << aluno.getNome() << "\n";

    // Professores que dão "Redes"
    std::cout << "\n--- Professores de Redes ---\n";
    auto profRedes = filtroProfessores.filtrarPorCondicao([](const Professor& p){
        return p.getDisciplinaPrincipal() == "Redes"; // precisa existir
    });
    for (const auto& prof : profRedes) std::cout << prof.getNome() << "\n";

    // Ordena alunos por nome
    filtroAlunos.ordenarPor([](const Aluno& a, const Aluno& b){
        return a.getNome() < b.getNome(); // precisa existir
    });

    std::cout << "\n--- Alunos ordenados por nome ---\n";
    filtroAlunos.imprimirTodos([](const Aluno& a){ std::cout << a.getNome() << "\n"; });

    return 0;
}