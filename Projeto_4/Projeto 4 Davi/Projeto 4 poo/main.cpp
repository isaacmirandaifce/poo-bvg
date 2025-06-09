#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

int main() {
    Aluno aluno1("Davi Nascimento", "202312345", "ADS");

    Disciplina d1("Programacao", 60, 7.5);
    Disciplina d2("Banco de Dados", 60, 5.8);

    aluno1.exibirInformacoes();

    std::cout << "\n--- Status das Disciplinas ---\n";
    std::cout << "Programacao: " << (verificarAprovacao(d1) ? "Aprovado" : "Reprovado") << "\n";
    std::cout << "Banco de Dados: " << (verificarAprovacao(d2) ? "Aprovado" : "Reprovado") << "\n";

    return 0;
}
