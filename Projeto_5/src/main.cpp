#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

int main() {
    std::vector<Usuario*> usuarios;

    Aluno* a1 = new Aluno("Carlos", "carlos@email.com", "1234", "Engenharia");
    a1->adicionarDisciplina("Cálculo");
    a1->adicionarDisciplina("Física");

    Professor* p1 = new Professor("Dra. Ana", "ana@uni.com", "Matemática");
    p1->adicionarDisciplina("Álgebra");
    p1->adicionarDisciplina("Geometria");

    FuncionarioAdministrativo* f1 = new FuncionarioAdministrativo("João", "joao@adm.com", "Financeiro", "Tesoureiro");

    Monitor* m1 = new Monitor("Lucas", "lucas@uni.com", "5678", "Computação", "Algoritmos");
    m1->Aluno::adicionarDisciplina("POO");
    m1->adicionarDisciplinaMonitorada("Estrutura de Dados");

    usuarios.push_back(a1);
    usuarios.push_back(p1);
    usuarios.push_back(f1);
    usuarios.push_back(m1);

    // polimorfismo: chamada dinâmica ao método gerarRelatorio
    for (Usuario* u : usuarios) {
        std::cout << "\n==== Gerando Relatório ====\n";
        u->gerarRelatorio();
    }

    std::cout << "\n==== Testando Sobrecarga ====\n";
    a1->exibirDetalhes(true);

    // liberação de memória
    for (Usuario* u : usuarios) delete u;

    return 0;
}
