#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

int main() {
    
    Aluno aluno("Matheus Cavalcante", "20230001", "ADS");

    Disciplina matematica("Matemática", 60, 7.5f);
    Disciplina programacao("Programação", 80, 5.8f);

    // Associando disciplinas ao aluno
    aluno.adicionarDisciplina(matematica);
    aluno.adicionarDisciplina(programacao);

    // Exibindo informações do aluno
    aluno.exibirInformacoes();
    std::cout << "\nDisciplinas:\n";
    aluno.exibirDisciplinas();

    // Verificando aprovação nas disciplinas
    std::cout << "\nStatus de aprovação:\n";
    for (const auto& disciplina : {matematica, programacao}) {
        std::cout << "Disciplina: " << disciplina.getNome() << " - "
                  << (verificarAprovacao(disciplina) ? "Aprovado" : "Reprovado") << std::endl;
    }

    return 0;
}
