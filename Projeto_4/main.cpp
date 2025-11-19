#include <iostream>
#include "include/Aluno.h"
#include "include/Disciplina.h"

int main(){
    // Criando um aluno
    Aluno aluno("John Lennon", "202500123", "ADS");
    aluno.exibirInformacoes();

    // Criando Disciplinas
    Disciplina d1 ("Programação Orientada a Objetos", 80);
    Disciplina d2 ("Redes de Computador", 60);

    // Atribuidor de Notas
    d1.setNota(7.5);
    d2.setNota(5.0);

    // Verificador de aprovação
    std::cout << "Resultado das Disciplinas \n";

    std::cout << "POO - Nota: " << d1.getNota();
    std::cout << (verificarAprovacao(d1) ? "APROVADO\n" : "REPROVADO\n");

    std::cout <<"RC - Nota: " << d2.getNota();
    std::cout << (verificarAprovacao(d2) ? "APROVADO\n" : "REPROVADO\n");

    return 0;
    }
