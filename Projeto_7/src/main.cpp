#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

#include "Filtro.h"
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Disciplina.h"

int main() {

    Filtro<Aluno> filtroAlunos;
    filtroAlunos.adicionarElemento(Aluno("Alice", "12345", 8.5));
    filtroAlunos.adicionarElemento(Aluno("Bob", "67890", 6.2));
    filtroAlunos.adicionarElemento(Aluno("Charlie", "11223", 7.8));
    filtroAlunos.adicionarElemento(Aluno("David", "44556", 9.1));
    filtroAlunos.adicionarElemento(Aluno("Eva", "77889", 6.9));

    std::cout << "--- Todos os Alunos ---" << std::endl;
    filtroAlunos.imprimirTodos([](const Aluno& a) { a.imprimir(); });

    std::cout << "\n--- Alunos com media acima de 7.0 ---" << std::endl;
    auto alunosComMediaAlta = filtroAlunos.filtrarPorCondicao([](const Aluno& a) {
        return a.getMediaGeral() > 7.0;
    });
    for (const auto& aluno : alunosComMediaAlta) {
        aluno.imprimir();
    }

    std::cout << "\n--- Alunos Ordenados por Nome ---" << std::endl;
    filtroAlunos.ordenar([](const Aluno& a1, const Aluno& a2) {
        return a1.getNome() < a2.getNome();
    });
    filtroAlunos.imprimirTodos([](const Aluno& a) { a.imprimir(); });

    std::cout << "\n--- Alunos Ordenados por Media (Decrescente) ---" << std::endl;
    filtroAlunos.ordenar([](const Aluno& a1, const Aluno& a2) {
        return a1.getMediaGeral() > a2.getMediaGeral();
    });
    filtroAlunos.imprimirTodos([](const Aluno& a) { a.imprimir(); });

    Filtro<Professor> filtroProfessores;
    Professor prof1("Dr. Souza", "Engenharia de Software");
    prof1.adicionarDisciplinaLecionada("POO");
    prof1.adicionarDisciplinaLecionada("Estrutura de Dados");
    filtroProfessores.adicionarElemento(prof1);

    Professor prof2("Dra. Lima", "Ciencia da Computacao");
    prof2.adicionarDisciplinaLecionada("POO");
    prof2.adicionarDisciplinaLecionada("Inteligencia Artificial");
    filtroProfessores.adicionarElemento(prof2);

    Professor prof3("Mestre Carlos", "Matematica");
    prof3.adicionarDisciplinaLecionada("Calculo I");
    filtroProfessores.adicionarElemento(prof3);

    std::cout << "\n--- Todos os Professores ---" << std::endl;
    filtroProfessores.imprimirTodos([](const Professor& p) { p.imprimir(); });

    std::cout << "\n--- Professores que ministram POO ---" << std::endl;
    auto professoresPOO = filtroProfessores.filtrarPorCondicao([](const Professor& p) {
        for (const auto& disc : p.getDisciplinasLecionadas()) {
            if (disc == "POO") {
                return true;
            }
        }
        return false;
    });
    for (const auto& professor : professoresPOO) {
        professor.imprimir();
    }

    Filtro<Disciplina> filtroDisciplinas;
    filtroDisciplinas.adicionarElemento(Disciplina("Programacao Orientada a Objetos", "POO001", 2024));
    filtroDisciplinas.adicionarElemento(Disciplina("Banco de Dados", "BD001", 2023));
    filtroDisciplinas.adicionarElemento(Disciplina("Estrutura de Dados", "ED001", 2024));
    filtroDisciplinas.adicionarElemento(Disciplina("Redes de Computadores", "RC001", 2023));

    std::cout << "\n--- Todas as Disciplinas ---" << std::endl;
    filtroDisciplinas.imprimirTodos([](const Disciplina& d) { d.imprimir(); });

    std::cout << "\n--- Disciplinas cursadas em 2024 (Exemplo com Aluno) ---" << std::endl;

    Aluno alunoExemplo("Fernanda", "99887", 8.0);
    alunoExemplo.adicionarDisciplinaCursada("Programacao Orientada a Objetos");
    alunoExemplo.adicionarDisciplinaCursada("Estrutura de Dados");
    alunoExemplo.adicionarDisciplinaCursada("Calculo I");

    std::cout << "Disciplinas cursadas por " << alunoExemplo.getNome() << " em 2024:" << std::endl;
    for (const auto& disciplinaNomeAluno : alunoExemplo.getDisciplinasCursadas()) {
        auto disciplinasDoAno = filtroDisciplinas.filtrarPorCondicao([&](const Disciplina& d) {
            return d.getNome() == disciplinaNomeAluno && d.getAno() == 2024;
        });
        if (!disciplinasDoAno.empty()) {
            disciplinasDoAno[0].imprimir(); 
        }
    }


    std::cout << "\n--- Testando Filtro com FuncionarioAdministrativo ---" << std::endl;
    Filtro<FuncionarioAdministrativo> filtroFuncionarios;
    filtroFuncionarios.adicionarElemento(FuncionarioAdministrativo("Ana Paula", "Secretaria"));
    filtroFuncionarios.adicionarElemento(FuncionarioAdministrativo("João Silva", "Diretor"));
    filtroFuncionarios.adicionarElemento(FuncionarioAdministrativo("Maria Oliveira", "Coordenadora"));

    std::cout << "\n--- Funcionarios com cargo de 'Secretaria' ---" << std::endl;
    auto secretarias = filtroFuncionarios.filtrarPorCondicao([](const FuncionarioAdministrativo& f) {
        return f.getCargo() == "Secretaria";
    });
    for (const auto& f : secretarias) {
        f.imprimir();
    }


    return 0;
}