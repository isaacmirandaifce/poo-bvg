#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

int main() {
    // Criar aluno
    Aluno aluno("Rikelme Moreira", "2025001", "ADS");

    // Criar disciplinas
    Disciplina d1("Algoritmos", 60, 7.5);
    Disciplina d2("Banco de Dados", 80, 5.5);

    // Associar disciplinas ao aluno
    aluno.adicionarDisciplina(d1);
    aluno.adicionarDisciplina(d2);

    // Exibir informações do aluno
    aluno.exibirInformacoes();

    // Verificar status de aprovação
    std::cout << "\nStatus das Disciplinas:\n";
    for (const auto& disciplina : aluno.getDisciplinas()) {
        std::cout << "- " << disciplina.getNome() << ": "
                  << (verificarAprovacao(disciplina) ? "Aprovado" : "Reprovado") << "\n";
    }

    return 0;
}
