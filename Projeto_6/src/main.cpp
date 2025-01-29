#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

int main() {
    Aluno aluno("Dagoberto", "60607070", "ADS", "dagoberto@gmail.com");
    aluno.adicionarDisciplina(Disciplina("POO", 60, 8.0f));
    aluno.adicionarDisciplina(Disciplina("Estruturas de Dados", 60, 7.0f));

    Professor professor("Joaninha", "joaninha123@gmail.com", "ADS", {"POO", "Algoritmos"});

    FuncionarioAdministrativo funcionario("Seu Raimundo", "raimundo@gmail.com", "RH", "Gerente");

    Monitor monitor("Patricia", "70707070", "Banco de Dados", "patricia@gmail.com", 
                    "Ciência de Dados", {"Estatística", "Inteligência Artificial"}, 
                    {"POO", "Estruturas de Dados"});

    aluno.gerarRelatorio();
    professor.gerarRelatorio();
    funcionario.gerarRelatorio();
    monitor.gerarRelatorio();

    return 0;
}
