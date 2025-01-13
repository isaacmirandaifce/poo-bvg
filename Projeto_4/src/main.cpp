#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

int main() {
    /* Criação de um aluno */
    Aluno aluno("Larissa Vieira", "2023123456", "ADS");
    
    /* Criação de disciplinas e atribuição de notas */
    Disciplina disciplina1("Matemática", 60);
    disciplina1.setNota(7.5);  /* Nota suficiente para aprovação */

    Disciplina disciplina2("Programação", 80);
    disciplina2.setNota(5.5);  /* Nota insuficiente para aprovação */

    /* Exibindo informações do aluno */
    aluno.exibirInformacoes();

   /* Verificando aprovação nas disciplinas */
    std::cout << "\nStatus de aprovação nas disciplinas:\n";
    std::cout << "Matemática: " << (verificarAprovacao(disciplina1) ? "Aprovado" : "Reprovado") << std::endl;
    std::cout << "Programação: " << (verificarAprovacao(disciplina2) ? "Aprovado" : "Reprovado") << std::endl;

    return 0;
}
