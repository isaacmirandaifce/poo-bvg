#include <iostream>
#include <string>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Filtro.h"

using namespace std;

int main() {

    // ===== CRIAÇÃO DE OBJETOS =====
    Aluno a1("Alissa", "alissa@email.com", "123", "202401", "ADS");
    a1.adicionarHistorico("POO", 2025, 9.5);
    a1.adicionarHistorico("ED", 2025, 8.0);

    Aluno a2("João", "joao@email.com", "321", "202402", "ADS");
    a2.adicionarHistorico("POO", 2025, 6.0);
    a2.adicionarHistorico("ED", 2025, 5.5);

    Professor p1("Carlos", "carlos@email.com", "123", "Computação");
    p1.disciplinasAdicionadas("POO");
    p1.disciplinasAdicionadas("Redes");

    Professor p2("Maria", "maria@email.com", "1234", "Matemática");
    p2.disciplinasAdicionadas("Cálculo");

    // ===== FILTROS =====
    Filtro<Aluno> filtroAlunos;
    filtroAlunos.adicionarElemento(a1);
    filtroAlunos.adicionarElemento(a2);

    Filtro<Professor> filtroProfessores;
    filtroProfessores.adicionarElemento(p1);
    filtroProfessores.adicionarElemento(p2);

    // ===== LOGIN =====
    int opcao;
    string senha;

    cout << "===== SISTEMA ACADEMICO =====\n";
    cout << "1 - Aluno\n2 - Professor\n3 - Funcionario Administrativo\nOpcao: ";
    cin >> opcao;

    cout << "Digite a senha: ";
    cin >> senha;

    // ===== PERFIL: ALUNO =====
    if (opcao == 1 && a1.autenticar(senha)) {

        cout << "\nLogin de ALUNO realizado com sucesso!\n";
        a1.gerarRelatorio();

        cout << "\nDISCIPLINAS DE 2025:\n";
        for (auto &h : a1.getHistorico()) {
            if (h.getAno() == 2025) {
                cout << "- " << h.getDisciplina() << endl;
            }
        }

        cout << "\nALUNOS COM MEDIA MAIOR QUE 7:\n";
        auto aprovados = filtroAlunos.filtrarPorCondicao(
            [](const Aluno& a) {
                return a.calcularMedia() > 7;
            }
        );

        for (auto &a : aprovados) {
            a.gerarRelatorio();
        }
    }

    // ===== PERFIL: PROFESSOR =====
    else if (opcao == 2 && p1.autenticar(senha)) {

        cout << "\nLogin de PROFESSOR realizado com sucesso!\n";
        p1.gerarRelatorio();

        cout << "\nPROFESSORES QUE MINISTRAM POO:\n";
        auto profsPOO = filtroProfessores.filtrarPorCondicao(
            [](const Professor& p) {
                return p.ministraDisciplina("POO");
            }
        );

        for (auto &p : profsPOO) {
            p.gerarRelatorio();
        }
    }

    // ===== PERFIL: FUNCIONÁRIO =====
    else if (opcao == 3) {
        cout << "\nPerfil de funcionario ainda em desenvolvimento.\n";
    }

    // ===== ERRO =====
    else {
        cout << "\nSenha incorreta ou opcao invalida. Acesso negado.\n";
    }

    return 0;
}
