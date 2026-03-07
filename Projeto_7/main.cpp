#include <iostream>
#include "include/Filtro.h"
#include "include/Aluno.h"


int main() {
    Filtro<Aluno> filtroAlunos;

    Aluno a1("Carlos", "123");
    Aluno a2("Anna", "123");
    Aluno a3("Bruno", "123");

    a1.adicionarDisciplina("POO", 2025, 8.5);
    a2.adicionarDisciplina("POO", 2025, 6.5);
    a3.adicionarDisciplina("POO", 2025, 9.0);

    filtroAlunos.adicionarElemento(a1);
    filtroAlunos.adicionarElemento(a2);
    filtroAlunos.adicionarElemento(a3);

    std::cout << "\n=== Todos os Alunos ===\n";

    filtroAlunos.imprimirTodos([](const Aluno& a){
        std::cout << a.getNome() << std::endl;
    });

    std::cout << "\n=== Alunos com nota acima de 7 ===\n";

    auto aprovados = filtroAlunos.filtrarPorCondicao([](const Aluno& a){
        const auto & historico = a.getHistorico();

        for(const auto& h : historico){
            if(h.nota >= 7.0){
                return true;
            }
        }

        return false;
    });

    for (const auto& a : aprovados){
        std::cout << a.getNome() << std::endl;
    }

    filtroAlunos.ordenar([](const Aluno& a, const Aluno& b){
        return a.getNome() < b.getNome();
    });

    std::cout << "\n=== Alunos ordenados por nome ===\n";

    filtroAlunos.imprimirTodos([](const Aluno& a){
        std::cout << a.getNome() << std::endl;
    });

    return 0;

    }

