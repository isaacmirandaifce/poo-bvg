#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Disciplina.h"

void exibirStatusDisciplina(const Disciplina& disciplina) {
    std::cout << "\nDisciplina: " << disciplina.getNome();
    std::cout << "\nCarga Horária: " << disciplina.getCargaHoraria() << "h";
    std::cout << "\nNota: " << disciplina.getNota();
    
    if (verificarAprovacao(disciplina)) {
        std::cout << "\nStatus: Aprovado\n";
    } else {
        std::cout << "\nStatus: Reprovado\n";
    }
}

int main() {
    // Criando um aluno
    Aluno aluno("João Silva", "20230001", "Análise e Desenvolvimento de Sistemas");
    
    // Criando disciplinas
    Disciplina poo("Programação Orientada a Objetos", 80, 7.5f);
    Disciplina estruturaDados("Estrutura de Dados", 60, 5.8f);
    
    // Exibindo informações do aluno
    aluno.exibirInformacoes();
    
    // Exibindo status nas disciplinas
    exibirStatusDisciplina(poo);
    exibirStatusDisciplina(estruturaDados);
    
    return 0;
}