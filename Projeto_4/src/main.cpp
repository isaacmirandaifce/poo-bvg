#include "../include/Aluno.h"
#include "../include/Disciplina.h"
#include <iostream>

int main() {
    // Criar objeto Aluno
    Aluno aluno("João Silva", "20240123", "Engenharia de Software");

    // Criar disciplinas
    Disciplina disciplina1("Algoritmos", 60);
    Disciplina disciplina2("Estruturas de Dados", 80);

    // Configurar notas
    disciplina1.setNota(7.5);
    disciplina2.setNota(5.8);

    // Exibir informações do aluno
    aluno.exibirInformacoes();

    // Verificar aprovação em cada disciplina
    std::cout << "\nVerificando aprovações:\n";
    std::cout << "Disciplina: Algoritmos - "
              << (verificarAprovacao(disciplina1) ? "Aprovado" : "Reprovado") << "\n";
    std::cout << "Disciplina: Estruturas de Dados - "
              << (verificarAprovacao(disciplina2) ? "Aprovado" : "Reprovado") << "\n";

    return 0;
}
