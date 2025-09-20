#include <iostream>
#include <string>
#include <vector>
#include "Filtro.h"
#include "Aluno.h"
#include "Professor.h"

int main() {
    // --- 1. Setup: Criando Alunos e Professores ---
    Aluno* a1 = new Aluno("Joao Silva", "joao@email.com", "senha123", "202301", "ADS");
    a1->adicionarDisciplinaAoHistorico("POO", 2025, 9.5);
    a1->adicionarDisciplinaAoHistorico("Estrutura de Dados", 2024, 6.5);

    Aluno* a2 = new Aluno("Ana Costa", "ana@email.com", "ana@123", "202205", "ADS");
    a2->adicionarDisciplinaAoHistorico("Banco de Dados", 2025, 8.0);

    Aluno* a3 = new Aluno("Carlos Pereira", "carlos@email.com", "carlos#1", "202102", "Redes");
    a3->adicionarDisciplinaAoHistorico("Calculo I", 2023, 6.0);

    Professor* p1 = new Professor("Maria Souza", "maria@email.com", "prof@abc", "Inteligencia Artificial");
    p1->adicionarDisciplina("Inteligencia Artificial");
    p1->adicionarDisciplina("Computacao Grafica");

    Professor* p2 = new Professor("Marcos Lima", "marcos@email.com", "prof@xyz", "Engenharia de Software");
    p2->adicionarDisciplina("Engenharia de Requisitos");

    // --- 2. Criando e Populando os Filtros Genéricos ---
    Filtro<Aluno*> filtroAlunos;
    filtroAlunos.adicionarElemento(a1);
    filtroAlunos.adicionarElemento(a2);
    filtroAlunos.adicionarElemento(a3);

    Filtro<Professor*> filtroProfessores;
    filtroProfessores.adicionarElemento(p1);
    filtroProfessores.adicionarElemento(p2);

    // --- 3. Demonstração das Funcionalidades ---
    std::cout << "--- SISTEMA DE FILTRAGEM E RELATORIOS ---\n" << std::endl;

    // A. Filtrar alunos com média acima de 7.0
    std::cout << ">> Alunos com media geral acima de 7.0:" << std::endl;
    Filtro<Aluno*> alunosAprovados = filtroAlunos.filtrarPorCondicao([](Aluno* a) {
        return a->getMediaGeral() > 7.0;
    });
    alunosAprovados.imprimirTodos([](Aluno* a) {
        std::cout << "  - " << a->getNome() << " (Media: " << a->getMediaGeral() << ")" << std::endl;
    });
    std::cout << "\n---------------------------------------------\n" << std::endl;

    // B. Listar professores que ministram uma disciplina específica
    std::cout << ">> Professores que ministram 'Inteligencia Artificial':" << std::endl;
    Filtro<Professor*> profsDeIA = filtroProfessores.filtrarPorCondicao([](Professor* p) {
        return p->ministraDisciplina("Inteligencia Artificial");
    });
    profsDeIA.imprimirTodos([](Professor* p) {
        std::cout << "  - " << p->getNome() << std::endl;
    });
    std::cout << "\n---------------------------------------------\n" << std::endl;

    // C. Listar disciplinas cursadas por um aluno em um determinado ano
    std::cout << ">> Disciplinas cursadas por " << a1->getNome() << " em 2025:" << std::endl;
    Filtro<Aluno::HistoricoDisciplinar> filtroHistorico;
    for (const auto& disciplina : a1->getHistorico()) {
        filtroHistorico.adicionarElemento(disciplina);
    }
    Filtro<Aluno::HistoricoDisciplinar> historico2025 = filtroHistorico.filtrarPorCondicao([](const Aluno::HistoricoDisciplinar& h) {
        return h.anoCursado == 2025;
    });
    historico2025.imprimirTodos([](const Aluno::HistoricoDisciplinar& h) {
        std::cout << "  - " << h.nomeDisciplina << " (Nota: " << h.nota << ")" << std::endl;
    });
    std::cout << "\n---------------------------------------------\n" << std::endl;

    // D. Ordenação genérica de alunos por nome
    std::cout << ">> Lista de todos os alunos (ordenada por nome):" << std::endl;
    filtroAlunos.ordenar([](Aluno* a, Aluno* b) {
        return a->getNome() < b->getNome();
    });
    filtroAlunos.imprimirTodos([](Aluno* a) {
        std::cout << "  - " << a->getNome() << std::endl;
    });

    // --- 4. Liberando a Memória ---
    std::cout << "\nLimpando memoria..." << std::endl;
    delete a1;
    delete a2;
    delete a3;
    delete p1;
    delete p2;

    return 0;
}
