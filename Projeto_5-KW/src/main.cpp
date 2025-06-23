#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

int main() {
    // Criação dos objetos
    Aluno* aluno = new Aluno("Maria", "maria@email.com", "2021001", "Engenharia");
    aluno->adicionarDisciplina("Matemática", 8.5f);
    aluno->adicionarDisciplina("Física", 7.0f);

    Professor* professor = new Professor("João", "joao@email.com", "Exatas");
    professor->adicionarDisciplina("Matemática");
    professor->adicionarDisciplina("Cálculo");

    FuncionarioAdministrativo* funcionario = new FuncionarioAdministrativo("Ana", "ana@email.com", "Secretaria", "Assistente");

    Monitor* monitor = new Monitor("Carlos", "carlos@email.com", "2021002", "Computação", "Exatas");
    monitor->adicionarDisciplinaMonitorada("Algoritmos");
    monitor->adicionarDisciplinaMonitorada("Estruturas de Dados");

    // Vetor de ponteiros para Usuario (polimorfismo)
    std::vector<Usuario*> usuarios;
    usuarios.push_back(aluno);
    usuarios.push_back(professor);
    usuarios.push_back(funcionario);
    usuarios.push_back(monitor);

    // Chamada polimórfica
    for (Usuario* u : usuarios) {
        u->gerarRelatorio();
        std::cout << "--------------------------\n";
    }

    // Teste de sobrecarga em Aluno
    std::cout << "Exibindo informações do aluno (sem notas):\n";
    aluno->exibirInformacoes();
    std::cout << "Exibindo informações do aluno (com notas):\n";
    aluno->exibirInformacoes(true);

    // Teste de método adicional em Monitor
    std::cout << "\nListando disciplinas monitoradas:\n";
    monitor->listarDisciplinasMonitoradas();

    // Liberação de memória
    for (Usuario* u : usuarios) {
        delete u;
    }

    return 0;
}