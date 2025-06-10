#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

int main() {
    Aluno aluno1("Lucas Silva", "2023001", "Sistemas de Informação");

    Disciplina disciplina1("Matemática", 60);
    Disciplina disciplina2("Programação", 80);

    disciplina1.setNota(7.5f);
    disciplina2.setNota(5.8f);

    aluno1.exibirInformacoes();
    std::cout << "--------------------------" << std::endl;

    disciplina1.exibirInformacoes();
    std::cout << "Status: " << (verificarAprovacao(disciplina1) ? "Aprovado" : "Reprovado") << std::endl;
    std::cout << "--------------------------" << std::endl;

    disciplina2.exibirInformacoes();
    std::cout << "Status: " << (verificarAprovacao(disciplina2) ? "Aprovado" : "Reprovado") << std::endl;
    
    return 0;
}

