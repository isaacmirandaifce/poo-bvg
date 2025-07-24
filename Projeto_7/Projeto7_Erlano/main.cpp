#include <iostream>
#include <vector>
#include <iomanip>
#include "src/Aluno/Aluno.h"
#include "src/Professor/Professor.h"
#include "src/Filtro/Filtro.h"

using namespace std;

int main() {
    cout << "===============================================" << endl;
    cout << "   SISTEMA ACADEMICO COM FILTROS GENERICOS   " << endl;
    cout << "===============================================" << endl << endl;

    // ===== TESTANDO FILTROS COM ALUNOS =====

    // Criando filtro genérico para alunos
    Filtro<Aluno> filtroAlunos;

    // Criando alunos
    Aluno a1("Rafael Maciel", "rafaelmn934@gmail.com", "Aluno", "123", "2023001", "ADS", {"POO", "ED"});
    Aluno a2("Erlano Benevides", "erlanosousa10@gmail.com", "Aluno", "456", "2023002", "ADS", {"BD", "LP"});
    Aluno a3("Guilherme Alves", "guilhermealves157@gmail.com", "Aluno", "789", "2023003", "ADS", {"POO", "ED"});
    Aluno a4("Helena", "oliveira.helena44@gmail.com", "Aluno", "101", "2023004", "Zootecnia", {"Calc", "Fisica"});

    // Adicionando histórico (notas)
    a1.adicionarDisciplinaAoHistorico("POO", 2024, 8.5);
    a1.adicionarDisciplinaAoHistorico("ED", 2024, 9.0);

    a2.adicionarDisciplinaAoHistorico("BD", 2024, 6.0);
    a2.adicionarDisciplinaAoHistorico("LP", 2024, 5.5);

    a3.adicionarDisciplinaAoHistorico("POO", 2024, 7.5);
    a3.adicionarDisciplinaAoHistorico("ED", 2024, 6.5);

    a4.adicionarDisciplinaAoHistorico("Calc", 2024, 9.5);
    a4.adicionarDisciplinaAoHistorico("Fisica", 2024, 8.0);

    // Adicionando ao filtro
    filtroAlunos.adicionarElemento(a1);
    filtroAlunos.adicionarElemento(a2);
    filtroAlunos.adicionarElemento(a3);
    filtroAlunos.adicionarElemento(a4);

    // Imprimindo todos os alunos
    cout << "=== TODOS OS ALUNOS (" << filtroAlunos.tamanho() << " total) ===" << endl;
    filtroAlunos.imprimirTodos([](const Aluno& a) {
        a.gerarRelatorio();
    });

    // Filtrando por média >= 7.0 (APROVADOS)
    cout << "=== ALUNOS APROVADOS (MEDIA >= 7.0) ===" << endl;
    auto aprovados = filtroAlunos.filtrarPorCondicao([](const Aluno& a) {
        return a.getMedia() >= 7.0;
    });

    for (const Aluno& a : aprovados) {
        cout << "✓ " << a.getNome() << " (Média: " << fixed << setprecision(2) << a.getMedia() << ")" << endl;
    }
    cout << "Total de aprovados: " << aprovados.size() << endl << endl;

    // Filtrando por curso ADS
    cout << "=== ALUNOS DO CURSO ADS ===" << endl;
    auto alunosADS = filtroAlunos.filtrarPorCondicao([](const Aluno& a) {
        return a.getCurso() == "ADS";
    });

    for (const Aluno& a : alunosADS) {
        cout << "- " << a.getNome() << " (Matrícula: " << a.getMatricula() << ")" << endl;
    }
    cout << endl;

    // Ordenando por nome
    cout << "=== ALUNOS ORDENADOS POR NOME ===" << endl;
    filtroAlunos.ordenar([](const Aluno& a1, const Aluno& a2) {
        return a1.getNome() < a2.getNome();
    });

    filtroAlunos.imprimirTodos([](const Aluno& a) {
        cout << "- " << a.getNome() << " | Curso: " << a.getCurso() << " | Média: " 
             << fixed << setprecision(2) << a.getMedia() << endl;
    });

    // Ordenando por média (decrescente)
    cout << "\n=== ALUNOS ORDENADOS POR MÉDIA (DECRESCENTE) ===" << endl;
    filtroAlunos.ordenar([](const Aluno& a1, const Aluno& a2) {
        return a1.getMedia() > a2.getMedia();
    });

    filtroAlunos.imprimirTodos([](const Aluno& a) {
        cout << "- " << a.getNome() << " | Média: " << fixed << setprecision(2) << a.getMedia() << endl;
    });

    cout << endl;

    // ===== TESTANDO FILTROS COM PROFESSORES =====

    cout << "=== TESTANDO FILTROS COM PROFESSORES ===" << endl;

    // Criando filtro genérico para professores
    Filtro<Professor> filtroProfessores;

    // Criando professores
    Professor p1("Isaac Miranda", "isaacmiranda@ifce.edu.br", "Professor", "pass123", "Computação", {"POO", "ED", "LP"});
    Professor p2("Augustavo", "luizaugustavo@ifce.edu.br", "Professor", "pass456", "Matemática", {"Calc", "Algebra"});
    Professor p3("Magno", "magnoprudencio@ifce.edu.br", "Professor", "pass789", "Computação", {"BD", "Redes"});

    // Adicionando ao filtro
    filtroProfessores.adicionarElemento(p1);
    filtroProfessores.adicionarElemento(p2);
    filtroProfessores.adicionarElemento(p3);

    // Listando todos os professores
    cout << "\n=== TODOS OS PROFESSORES ===" << endl;
    filtroProfessores.imprimirTodos([](const Professor& p) {
        p.gerarRelatorio();
    });

    // Filtrando professores que ministram POO
    cout << "=== PROFESSORES QUE MINISTRAM POO ===" << endl;
    auto professorsPOO = filtroProfessores.filtrarPorCondicao([](const Professor& p) {
        return p.ministraDisciplina("POO");
    });

    for (const Professor& p : professorsPOO) {
        cout << "- " << p.getNome() << " (Área: " << p.getAreaDeAtuacao() << ")" << endl;
    }
    cout << endl;

    // Filtrando por área de atuação
    cout << "=== PROFESSORES DA ÁREA DE COMPUTAÇÃO ===" << endl;
    auto professorsComp = filtroProfessores.filtrarPorCondicao([](const Professor& p) {
        return p.getAreaDeAtuacao() == "Computação";
    });

    for (const Professor& p : professorsComp) {
        cout << "- " << p.getNome() << endl;
    }
}