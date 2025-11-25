#include <iostream>
#include <vector>

#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"
#include "Disciplina.h"

int main() {
    // Criando algumas disciplinas
    Disciplina logica("Lógica de Programação", 60);
    Disciplina poo("Programação Orientada a Objetos", 80);

    logica.setNota(7.5f);
    poo.setNota(5.0f);

    // Aluno
    Aluno* aluno1 = new Aluno("Maria Souza", "maria@ifce.edu.br", "20231001", "ADS");
    aluno1->adicionarDisciplina(logica);
    aluno1->adicionarDisciplina(poo);

    // Professor
    std::vector<std::string> materiasProf;
    materiasProf.push_back("Lógica de Programação");
    materiasProf.push_back("Estrutura de Dados");

    Professor* prof1 = new Professor("Ricardo Lima", "ricardo@ifce.edu.br",
                                     "Computação", materiasProf);

    // Funcionário administrativo
    FuncionarioAdministrativo* func1 =
        new FuncionarioAdministrativo("Ana Paula", "ana@ifce.edu.br",
                                      "Secretaria Acadêmica", "Assistente");

    // Monitor (herança múltipla: Aluno + Professor)
    std::vector<std::string> materiasMonitoradas;
    materiasMonitoradas.push_back("Lógica de Programação");

    Monitor* monitor1 = new Monitor("Lucas Ferreira", "lucas@ifce.edu.br",
                                    "20232015", "ADS",
                                    "Computação", materiasProf,
                                    materiasMonitoradas);

    // Polimorfismo: vetor de ponteiros para Usuario
    std::vector<Usuario*> usuarios;
    usuarios.push_back(aluno1);
    usuarios.push_back(prof1);
    usuarios.push_back(func1);
    usuarios.push_back(monitor1);

    std::cout << "===== RELATORIOS GERAIS =====" << std::endl;
    for (Usuario* u : usuarios) {
        u->gerarRelatorio();   // chamada polimórfica
        std::cout << std::endl;
    }

    std::cout << "===== SOBRECARGA EM ALUNO =====" << std::endl;
    // versão simples
    aluno1->exibirInformacoes();
    std::cout << std::endl;
    // versão sobrecarregada, mostrando também as disciplinas
    aluno1->exibirInformacoes(true);

    std::cout << std::endl << "===== DISCIPLINAS MONITORADAS =====" << std::endl;
    monitor1->listarDisciplinasMonitoradas();

    // Liberando memória
    for (Usuario* u : usuarios) {
        delete u;
    }

    return 0;
}
