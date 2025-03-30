#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

int main() {
    // Criação do objeto Aluno
    Aluno aluno("João Silva", "20250101", "Análise e Desenvolvimento de Sistemas");

    // Criação dos objetos Disciplina
    Disciplina disciplina1("Programação", 60, 7.5f);
    Disciplina disciplina2("Banco de Dados", 40, 5.0f);

    // Exibindo informações do aluno
    aluno.exibirInformacoes();

    // Verificando aprovação nas disciplinas
    std::cout << "\nStatus de Aprovação:\n";
    std::cout << "Disciplina: " << "Programação" << " - "
              << (verificarAprovacao(disciplina1) ? "Aprovado" : "Reprovado") << "\n";
    std::cout << "Disciplina: " << "Banco de Dados" << " - "
              << (verificarAprovacao(disciplina2) ? "Aprovado" : "Reprovado") << "\n";

    return 0;
}
