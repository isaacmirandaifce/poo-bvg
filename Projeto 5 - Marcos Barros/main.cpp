#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

int main() {
    std::vector<Usuario*> usuarios;

    Aluno* aluno1 = new Aluno("Ana Lima", "ana@exemplo.com", "2023123", "ADS");
    aluno1->adicionarDisciplina("POO");
    aluno1->adicionarDisciplina("Banco de Dados");

    Professor* prof1 = new Professor("Carlos Souza", "carlos@exemplo.com", "Engenharia de Software");
    prof1->adicionarDisciplina("POO");
    prof1->adicionarDisciplina("Análise de Sistemas");

    FuncionarioAdministrativo* func1 = new FuncionarioAdministrativo("Marcia Alves", "marcia@exemplo.com", "RH", "Secretária");

    Monitor* monitor1 = new Monitor("Pedro Rocha", "pedro@exemplo.com", "2023987", "ADS", "Redes");
    monitor1->adicionarDisciplinaMonitorada("Redes I");
    monitor1->adicionarDisciplinaMonitorada("Infraestrutura");

    usuarios.push_back(aluno1);
    usuarios.push_back(prof1);
    usuarios.push_back(func1);
    usuarios.push_back(monitor1);

    for (auto u : usuarios) {
        u->gerarRelatorio();
        std::cout << "----------------------\n";
    }

    for (auto u : usuarios) delete u;

    return 0;
}
