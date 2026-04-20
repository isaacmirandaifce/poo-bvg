#include <iostream>
#include "aluno.h"
#include "disciplina.h"

int main() {

    Aluno aluno("Joao Paulo", "20242283000292", "Análise e Desenvolvimento de Sistemas");

    Disciplina d1("Programacao Orientada a Objetos", 80);
    Disciplina d2("Banco de Dados", 80);

    d1.setNota(7.5);
    d2.setNota(5.8);

    aluno.exibirInformacoes();

    std::cout << "\nDisciplina: " << d1.getNome() << std::endl;
    std::cout << "Nota: " << d1.getNota() << std::endl;
    std::cout << "Status: " 
              << (verificarAprovacao(d1) ? "Aprovado" : "Reprovado") 
              << std::endl;

    std::cout << "\nDisciplina: " << d2.getNome() << std::endl;
    std::cout << "Nota: " << d2.getNota() << std::endl;
    std::cout << "Status: " 
              << (verificarAprovacao(d2) ? "Aprovado" : "Reprovado") 
              << std::endl;

    return 0;
}
