#include "../include/aluno.h"
#include "../include/disciplina.h"
#include <iostream>

int main() {
    // Criando aluno
    Aluno aluno("Kaella Sales", "12345", "Analise e Desenvolvimento de Sistemas");

    // Criando disciplinas
    Disciplina disciplina1("Matematica", 60, 7.5);
    Disciplina disciplina2("Programacao", 80, 5.8);

    // Exibindo informações do aluno
    aluno.exibirInformacoes();
    std::cout << "\nInformacoes das Disciplinas:\n";

    // Exibindo informações das disciplinas e verificando aprovação
    disciplina1.exibirInformacoes();
    std::cout << (verificarAprovacao(disciplina1) ? "Aprovado!\n" : "Reprovado!\n") << std::endl;

    disciplina2.exibirInformacoes();
    std::cout << (verificarAprovacao(disciplina2) ? "Aprovado!\n" : "Reprovado!\n") << std::endl;

    return 0;
}
