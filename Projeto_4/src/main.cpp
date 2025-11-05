#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

int main() {
    Aluno a("João Silva", "202312345", "Análise e Desenvolvimento de Sistemas");

    Disciplina d1("Programação I", 60);
    Disciplina d2("Matemática Discreta", 45);

    d1.setNota(7.5f);
    d2.setNota(5.0f);
    // associar disciplinas ao aluno
    a.adicionarDisciplina(d1);
    a.adicionarDisciplina(d2);

    std::cout << "Informações do aluno:" << std::endl;
    a.exibirInformacoes();
    std::cout << std::endl;

    // exibir disciplinas e situação usando a função amiga
    a.exibirDisciplinas();

    return 0;
}
