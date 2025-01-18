#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

int main() {
    Aluno aluno("Gabriel", "499142", "Engenharia da Computacao");
    
    Disciplina disciplina1("Matematica", 60, 7.5f);
    Disciplina disciplina2("Programacao", 90, 5.8f);

    aluno.adicionarDisciplina(disciplina1);
    aluno.adicionarDisciplina(disciplina2);

    aluno.exibirInformacoes();

    for (const auto& disciplina : aluno.getDisciplinas()) {
        std::cout << "Disciplina: " << disciplina.getNome() << " - Nota: " << disciplina.getNota()
                  << " - " << (verificarAprovacao(disciplina) ? "Aprovado" : "Reprovado") << "\n";
    }

    return 0;
}
