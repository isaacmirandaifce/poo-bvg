#include <iostream>
#include <vector>
#include <string>
#include "Filtro.h"
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"

float calcularMediaAluno(const Aluno& a) {
    const auto& hist = a.getHistorico();
    if (hist.empty()) return 0.0f;
    float soma = 0.0f;
    for (const auto& h : hist) soma += h.getNota();
    return soma / hist.size();
}

int main() {
    // Criando disciplinas
    Disciplina mat("Matemática", 60, 8.5f);
    Disciplina prog("Programação", 80, 7.2f);
    Disciplina filo("Filosofia", 40, 5.0f);

    // Professores
    Professor p1("Ana Silva", "ana@uni.edu", "Matemática", {"Matemática"});
    Professor p2("Carlos Souza", "carlos@uni.edu", "Computação", {"Programação"});

    // Alunos
    Aluno a1("João", "joao@uni.edu", "M001", "Engenharia");
    a1.adicionarDisciplina(mat);
    a1.adicionarDisciplina(prog);
    a1.adicionarHistorico("Matemática", 2024, 8.0f);
    a1.adicionarHistorico("Programação", 2024, 7.0f);

    Aluno a2("Maria", "maria@uni.edu", "M002", "Direito");
    a2.adicionarDisciplina(filo);
    a2.adicionarHistorico("Filosofia", 2023, 5.0f);

    Aluno a3("Bruno", "bruno@uni.edu", "M003", " Ciência da Computação");
    a3.adicionarDisciplina(prog);
    a3.adicionarHistorico("Programação", 2024, 9.0f);
    a3.adicionarHistorico("Matemática", 2024, 8.0f);

    // Filtros
    Filtro<Aluno> filtroAlunos;
    filtroAlunos.adicionarElemento(a1);
    filtroAlunos.adicionarElemento(a2);
    filtroAlunos.adicionarElemento(a3);

    Filtro<Professor> filtroProfessores;
    filtroProfessores.adicionarElemento(p1);
    filtroProfessores.adicionarElemento(p2);

    // 1) Filtrar alunos com média acima de 7.0
    std::cout << "Alunos com média > 7.0:" << std::endl;
    auto acima7 = filtroAlunos.filtrarPorCondicao([](const Aluno& al) {
        const auto& h = al.getHistorico();
        if (h.empty()) return false;
        float soma = 0.0f;
        for (const auto& it : h) soma += it.getNota();
        return (soma / h.size()) > 7.0f;
    });
    for (const auto& a : acima7) std::cout << "- " << a.getNome() << std::endl;

    // 2) Listar professores que ministram uma disciplina específica
    std::string busca = "Programação";
    std::cout << "\nProfessores que ministram '" << busca << "':" << std::endl;
    auto profs = filtroProfessores.filtrarPorCondicao([&](const Professor& p){
        for (const auto& d : p.getDisciplinasMinistradas()) if (d == busca) return true;
        return false;
    });
    for (const auto& p : profs) std::cout << "- " << p.getNome() << std::endl;

    // 3) Listar disciplinas cursadas por um aluno em um determinado ano
    int anoBusca = 2024;
    std::cout << "\nDisciplinas cursadas por " << a1.getNome() << " em " << anoBusca << ":" << std::endl;
    for (const auto& h : a1.getHistorico()) {
        if (h.getAno() == anoBusca) std::cout << "- " << h.getNome() << " (Nota: " << h.getNota() << ")" << std::endl;
    }

    // 4) Ordenação genérica de alunos por nome
    std::cout << "\nAlunos ordenados por nome:" << std::endl;
    filtroAlunos.ordenarPor([](const Aluno& x, const Aluno& y){ return x.getNome() < y.getNome(); });
    filtroAlunos.imprimirTodos([](const Aluno& al){ std::cout << "- " << al.getNome() << std::endl; });

    return 0;
}
