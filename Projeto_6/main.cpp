#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Criando Aluno
    Aluno aluno("João", "joao@email.com", "senha123");
    aluno.adicionarDisciplina("Matemática", 2023, 9.0);
    aluno.adicionarDisciplina("Física", 2023, 8.5);

    // Criando Professor
    Professor professor("Maria", "maria@email.com", "senha456", 
                        "Computação", {"POO", "Estruturas de Dados"});

    // Criando Funcionário Administrativo
    FuncionarioAdministrativo funcionario("Carlos", "carlos@email.com", "senha789", 
                                          "Financeiro", "Gerente");

    // Testando autenticação e relatórios
    if (aluno.autenticar("senha123")) {
        cout << "\nAutenticação bem-sucedida (Aluno):\n";
        aluno.gerarRelatorio();
    } else {
        cout << "\nFalha na autenticação (Aluno).\n";
    }

    if (professor.autenticar("senha456")) {
        cout << "\nAutenticação bem-sucedida (Professor):\n";
        professor.gerarRelatorio();
    } else {
        cout << "\nFalha na autenticação (Professor).\n";
    }

    if (funcionario.autenticar("senha789")) {
        cout << "\nAutenticação bem-sucedida (Funcionário Administrativo):\n";
        funcionario.gerarRelatorio();
    } else {
        cout << "\nFalha na autenticação (Funcionário Administrativo).\n";
    }

    return 0;
}
