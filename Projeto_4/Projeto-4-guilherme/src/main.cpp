#include <iostream>
#include "aluno.h"
#include "disciplina.h"

int main() {
    Aluno aluno("João da Silva", "2023123456", "Análise e Desenvolvimento de Sistemas");

    Disciplina d1("Algoritmos", 60, 7.5);
    Disciplina d2("Banco de Dados", 80, 5.2);

    aluno.exibirInformacoes();
    std::cout << "\nStatus nas Disciplinas:\n";

    d1.exibirDados();
    std::cout << "Status: " << (verificarAprovacao(d1) ? "Aprovado" : "Reprovado") << "\n\n";

    d2.exibirDados();
    std::cout << "Status: " << (verificarAprovacao(d2) ? "Aprovado" : "Reprovado") << "\n";

    return 0;
}
