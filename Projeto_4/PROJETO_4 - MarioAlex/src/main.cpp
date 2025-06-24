#include <iostream>
#include "aluno.h"
#include "disciplina.h"

int main() {
    Aluno aluno1("Mario Teste", "20251234", "Análise e Desenvolvimento de Sistemas");

    Disciplina d1("Programação", 60, 7.5);
    Disciplina d2("Banco de Dados", 60, 5.9);

    aluno1.exibirInformacoes();
    std::cout << "----------------------" << std::endl;

    verificarAprovacao(d1);
    verificarAprovacao(d2);

    return 0;
}
