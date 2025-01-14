#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

int main() {
    // Criação de Aluno
    Aluno aluno1("João Silva", "2023001", "Engenharia");

    // Criação de disciplinas
    Disciplina disciplina1("Matemática", 60);
    Disciplina disciplina2("Física", 45);

    // Configurando as notas
    disciplina1.setNota(7.5);
    disciplina2.setNota(5.8);

    // Exibindo informações do aluno
    aluno1.exibirInformacoes();

    // Verificando status de aprovação
    std::cout << "Status das disciplinas:\n";

    std::cout << disciplina1.getNome() << ": ";
    if (verificarAprovacao(disciplina1)) {
        std::cout << "Aprovado\n";
    } else {
        std::cout << "Reprovado\n";
    }

    std::cout << disciplina2.getNome() << ": ";
    if (verificarAprovacao(disciplina2)) {
        std::cout << "Aprovado\n";
    } else {
        std::cout << "Reprovado\n";
    }

    return 0;
}
