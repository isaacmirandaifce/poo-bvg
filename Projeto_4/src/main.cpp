#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

int main() {
    Aluno aluno("Aerton Silva", "20241234", "ADS");

    Disciplina d1("Programacao Orientada a Objetos", 60);
    Disciplina d2("Estrutura de Dados", 80);

    d1.setNota(7.5);
    d2.setNota(5.8);

    aluno.exibirInformacoes();
    std::cout << "========================" << std::endl;

    verificarAprovacao(d1);
    verificarAprovacao(d2);

    return 0;
}
