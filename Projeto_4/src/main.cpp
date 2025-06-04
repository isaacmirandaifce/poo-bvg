#include <iostream> 
#include "Aluno.h"  
#include "Disciplina.h" 

int main() {
    Aluno aluno1("Maria Silva", "2023001", "Analise e Desenvolvimento de Sistemas");

    aluno1.exibirInformacoes();

    Disciplina lp1("Linguagem de Programacao I", 80);
    Disciplina bd1("Banco de Dados I", 60);

    lp1.setNota(7.5f); 
    bd1.setNota(5.8f); 

    std::cout << "\n--- Verificando Aprovacao ---" << std::endl;

    verificarAprovacao(lp1);
    verificarAprovacao(bd1);

    std::cout << "\n--- Fim do Programa ---" << std::endl;

    return 0; 
}