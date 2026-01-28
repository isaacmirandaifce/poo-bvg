#include <iostream>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"

using namespace std;

int main() {

    // Criando usuários do sistema
    Aluno aluno("Alissa", "alissa@email.com", "1234", "202401", "ADS");
    aluno.adicionarHistorico("POO", 2025, 9.5);
    aluno.adicionarHistorico("Estrutura de Dados", 2025, 8.7);

    Professor professor("Carlos", "carlos@email.com", "abcd", "Computação");
    professor.disciplinasAdicionadas("POO");
    professor.disciplinasAdicionadas("Redes");

    FuncionarioAdministrativo func("Ana", "ana@email.com", "9999", "Secretaria", "Coordenadora");

    cout << "===== SISTEMA ACADEMICO =====\n";
    cout << "Escolha o tipo de usuario para login:\n";
    cout << "1 - Aluno\n";
    cout << "2 - Professor\n";
    cout << "3 - Funcionario Administrativo\n";
    cout << "Opcao: ";

    int op;
    cin >> op;

    string senha;

    cout << "\nDigite a senha: ";
    cin >> senha;

    bool autenticado = false;

    if (op == 1) {
        autenticado = aluno.autenticar(senha);
        if (autenticado) {
            cout << "\nLogin realizado com sucesso!\n";
            aluno.gerarRelatorio();
        }
    }
    else if (op == 2) {
        autenticado = professor.autenticar(senha);
        if (autenticado) {
            cout << "\nLogin realizado com sucesso!\n";
            professor.gerarRelatorio();
        }
    }
    else if (op == 3) {
        autenticado = func.autenticar(senha);
        if (autenticado) {
            cout << "\nLogin realizado com sucesso!\n";
            func.gerarRelatorio();
        }
    }
    else {
        cout << "Opcao invalida.\n";
        return 0;
    }

    if (!autenticado) {
        cout << "\nSenha incorreta. Acesso negado.\n";
    }

    return 0;
}
