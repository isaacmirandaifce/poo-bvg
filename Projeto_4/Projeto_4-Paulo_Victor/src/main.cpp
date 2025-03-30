#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

int main() {
    Aluno aluno("Joao Silva", "20230001", "Ciencia da Computacao");

    Disciplina disciplina1("Matematica", 60, 7.5f);
    Disciplina disciplina2("Programacao", 80, 5.8f);

    aluno.adicionarDisciplina(disciplina1);
    aluno.adicionarDisciplina(disciplina2);

    aluno.exibirInformacoes();

    return 0;
}