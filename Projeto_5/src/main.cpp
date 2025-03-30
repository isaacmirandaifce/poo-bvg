#include <iostream>
#include "../include/aluno.h"
#include "../include/professor.h"
#include "../include/funcionarioaAdministrativo.h"
#include "../include/monitor.h"
#include "../include/disciplina.h"

int main() {
    // Criando instâncias de Aluno, Professor, FuncionarioAdministrativo e Monitor
    Aluno aluno("Kaella Sales", "kaella@email.com", "Aluno", "ADS");
    aluno.adicionarDisciplina(std::make_shared<Disciplina>("Matematica", 60, 7.5));
    aluno.adicionarDisciplina(std::make_shared<Disciplina>("Programacao", 80, 5.8));

    Professor professor("Joao Silva", "joao@email.com", "Professor", "Computacao");
    professor.adicionarDisciplina("Algoritmos");
    professor.adicionarDisciplina("Estruturas de Dados");

    FuncionarioAdministrativo funcionario("Maria Oliveira", "maria@email.com", "Funcionario", "Secretaria", "Assistente");

    Monitor monitor("Carlos Souza", "carlos@email.com", "Aluno", "Fisica");
    monitor.adicionarDisciplina(std::make_shared<Disciplina>("Fisica I", 60, 8.0));
    monitor.adicionarDisciplina(std::make_shared<Disciplina>("Fisica II", 60, 9.0));

    // Exibindo informações de cada um
    std::cout << "\nInformacoes do Aluno:\n";
    aluno.gerarRelatorio();

    std::cout << "\nInformacoes do Professor:\n";
    professor.gerarRelatorio();

    std::cout << "\nInformacoes do Funcionario Administrativo:\n";
    funcionario.gerarRelatorio();

    std::cout << "\nInformacoes do Monitor:\n";
    monitor.gerarRelatorio();

    return 0;
}
