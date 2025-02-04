#include <iostream>
#include "aluno.h"
#include "disciplina.h"
#include "filtro.h"
#include "professor.h"
#include "funcionario_administrativo.h"

using namespace std;

int main() {
    // criando objetos aluno
    Aluno aluno1("Alanna Texeira", "202510001", "Análise e Desenvolvimento de Sistemas");
    Aluno aluno2("Vitoria Nunez", "202510002", "Engenharia da Computação");

    // criando objetos disciplina
    Disciplina disciplina1("Introdução a C++", 60, 7.5f);
    Disciplina disciplina2("Banco de Dados", 45, 5.8f);
    Disciplina disciplina3("Segurança de Dados", 50, 8.0f);

    // criando objetos professor
    Professor professor1("Lucas Araújo", "P001", "Introdução a C++");
    Professor professor2("Pedro Emanoel", "P002", "Banco de Dados");

    // criando objetos funcionário administrativo
    FuncionarioAdministrativo func1("Armani Oliveira", "F001", "Secretaria Acadêmica");

    // criando filtros genéricos
    Filtro<Aluno> filtroAlunos;
    filtroAlunos.adicionarElemento(aluno1);
    filtroAlunos.adicionarElemento(aluno2);

    Filtro<Disciplina> filtroDisciplinas;
    filtroDisciplinas.adicionarElemento(disciplina1);
    filtroDisciplinas.adicionarElemento(disciplina2);
    filtroDisciplinas.adicionarElemento(disciplina3);

    Filtro<Professor> filtroProfessores;
    filtroProfessores.adicionarElemento(professor1);
    filtroProfessores.adicionarElemento(professor2);

    // exibindo informações
    cout << "Lista de Alunos:" << endl;
    filtroAlunos.imprimirTodos([](const Aluno& aluno) {
        aluno.exibirInformacoes();
        cout << endl;
    });

    cout << "\nProfessores que ministram Banco de Dados:" << endl;
    auto professoresBD = filtroProfessores.filtrarPorCondicao([](const Professor& p) {
        return p.getDisciplina() == "Banco de Dados";
    });

    for (const auto& p : professoresBD) {
        p.exibirInformacoes();
    }

    return 0;
}
