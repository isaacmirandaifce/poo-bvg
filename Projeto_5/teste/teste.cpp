#include <iostream>
#include "../src/Aluno.hpp"
#include "../src/Professor.hpp"
#include "../src/FuncionarioAdministrativo.hpp"
#include "../src/Monitor.hpp"


int main() {
    // Criar um Aluno
    Aluno aluno("Carlos Silva", "carlos@email.com", "2023001", "Engenharia");
    aluno.adicionarDisciplina("Calculo");
    aluno.adicionarDisciplina("Fisica");
    aluno.adicionarNota(8.5f);
    aluno.adicionarNota(7.0f);

    // Exibir relatório do Aluno
    aluno.gerarRelatorio();
    aluno.exibirInformacoes();
    aluno.exibirInformacoes(true);  // Com notas

    // Criar um Professor
    Professor prof("Ana Lima", "ana@email.com", "Matematica");
    prof.adicionarDisciplina("Calculo");
    prof.adicionarDisciplina("Algebra");
    prof.gerarRelatorio();

    // Criar um Funcionário Administrativo
    FuncionarioAdministrativo func("Joao Souza", "joao@email.com", "Financeiro", "Gerente");
    func.gerarRelatorio();

    // Criar um Monitor
    Monitor monitor("Mariana Costa", "mariana@email.com", "2023002", "Ciencia da Computacao", "Logica de Programacao");
    
    // Adicionar disciplinas como Aluno e como Professor, via métodos específicos para evitar ambiguidade
    monitor.adicionarDisciplinaAluno("Programacao C++");
    monitor.adicionarDisciplinaProfessor("Logica de Programacao");

    // Adicionar disciplinas monitoradas
    monitor.adicionarDisciplinaMonitorada("Estruturas de Dados");
    monitor.adicionarDisciplinaMonitorada("Banco de Dados");

    // Gerar relatório do Monitor
    monitor.gerarRelatorio();

    return 0;
}
