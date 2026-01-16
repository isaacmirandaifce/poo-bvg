#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Disciplina.h"
// Função para exibir o status de aprovação do aluno em uma disciplina específica
// Recebe um objeto Disciplina e mostra nome, carga horária, nota e resultado (aprovado/reprovado)
void exibirStatusDisciplina(const Disciplina& disciplina) {
std::cout << "\nDisciplina: " << disciplina.getNome();
std::cout << "\nCarga Horária: " << disciplina.getCargaHoraria() << "h";
std::cout << "\nNota: " << disciplina.getNota();
// Chama a função amiga para verificar se o aluno foi aprovado (nota >= 6.0)
if (verificarAprovacao(disciplina)) {
std::cout << "\nStatus: Aprovado\n";
} else {
std::cout << "\nStatus: Reprovado\n";
}
}


int main() {
// Criação de um objeto da classe Aluno com nome, matrícula e curso
Aluno aluno("João Silva", "20230001", "Análise e Desenvolvimento de Sistemas");
// Criação de objetos da classe Disciplina, com nome, carga horária e nota inicial
Disciplina poo("Programação Orientada a Objetos", 80, 7.5f);
Disciplina estruturaDados("Estrutura de Dados", 60, 5.8f);
// Exibe as informações gerais do aluno
aluno.exibirInformacoes();
// Exibe o status (aprovado/reprovado) para cada disciplina
exibirStatusDisciplina(poo);
exibirStatusDisciplina(estruturaDados);
return 0; // Finaliza o programa
}