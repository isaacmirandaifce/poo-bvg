#include <iostream>
#include <vector>
#include "Usuario.h"
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

int main() {
 
    std::vector<Usuario*> bancoDeDados;

    
    Aluno* aluno1 = new Aluno("Lucas Silva", "lucas@email.com", "Graduacao", "2026001", "Engenharia");
    aluno1->adicionarDisciplina("Calculo I");
    aluno1->adicionarDisciplina("Programacao C++");

    std::vector<std::string> discProf = {"Programacao C++", "Estrutura de Dados"};
    Professor* prof1 = new Professor("Dr. Carlos", "carlos@email.com", "Docente", "Computacao", discProf);

    FuncionarioAdministrativo* func1 = new FuncionarioAdministrativo("Ana Souza", "ana@email.com", "Admin", "RH", "Analista");

    Monitor* monitor1 = new Monitor("Mariana", "mari@email.com", "Monitoria", "2024005", "Ciencia da Computacao", "Algoritmos", discProf);
    monitor1->adicionarMonitoria("Introducao a Programacao");


    bancoDeDados.push_back(aluno1);
    bancoDeDados.push_back(prof1);
    bancoDeDados.push_back(func1);
    bancoDeDados.push_back(monitor1);

    std::cout << "=== EXIBINDO RELATORIOS POLIMORFICOS ===" << std::endl << std::endl;
    for(Usuario* u : bancoDeDados) {
        u->gerarRelatorio(); 
        std::cout << std::endl;
    }

    std::cout << "=== DEMONSTRANDO SOBRECARGA EM ALUNO ===" << std::endl;
    aluno1->exibirInformacoesDetalhadas();
    std::vector<double> notasLucas = {8.5, 9.0, 7.5};
    aluno1->exibirInformacoesDetalhadas(notasLucas);


    for(Usuario* u : bancoDeDados) {
        delete u;
    }

    return 0;
}