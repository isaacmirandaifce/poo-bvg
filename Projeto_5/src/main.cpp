#include <iostream>
#include "Aluno.hpp"
#include "Professor.hpp"
#include "FuncionarioAdministrativo.hpp"
#include "Monitor.hpp"

int main() {
    std::cout << "===== Sistema Acadêmico - Modo Principal =====\n";

    Aluno aluno("João Silva", "joao@email.com", "2023001", "Engenharia");
    aluno.adicionarDisciplina("Matemática");
    aluno.adicionarNota(8.5);
    aluno.exibirInformacoes(true);

    Professor prof("Maria Costa", "maria@email.com", "Ciência da Computação");
    prof.adicionarDisciplina("POO");
    prof.gerarRelatorio();

    FuncionarioAdministrativo func("Carlos Lima", "carlos@email.com", "Financeiro", "Analista");
    func.gerarRelatorio();

    Monitor monitor("Ana Souza", "ana@email.com", "2023010", "Sistemas", "TI");
    monitor.adicionarDisciplinaMonitorada("Algoritmos");
    monitor.gerarRelatorio();

    return 0;
}
