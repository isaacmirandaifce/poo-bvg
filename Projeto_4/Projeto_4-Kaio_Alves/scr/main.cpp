#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

using namespace std;

int main() {
    // Criando objetos de alunos
    Aluno aluno1("João Silva", "12345", "Análise e Desenvolvimento de Sistemas");
    Aluno aluno2("Maria Souza", "67890", "Análise e Desenvolvimento de Sistemas");

    // Criando objetos de disciplinas
    Disciplina disciplina1("Matemática", 60);
    Disciplina disciplina2("Programação", 80);

    // Definindo notas
    disciplina1.setNota(7.5);
    disciplina2.setNota(5.5);

    // Exibindo informações dos alunos
    aluno1.exibirInformacoes();
    aluno2.exibirInformacoes();

    // Verificando aprovação usando a função amiga
    verificarAprovacao(aluno1, disciplina1);
    verificarAprovacao(aluno1, disciplina2);
    verificarAprovacao(aluno2, disciplina1);
    verificarAprovacao(aluno2, disciplina2);

    system("pause");

    return 0;
}