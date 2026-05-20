#include <iostream>
#include <iomanip>
#include "Aluno.h"
#include "Disciplina.h"

int main() {
    // Criando o objeto Aluno com construtor parametrizado
    Aluno aluno("Carlos Eduardo Silva", "2024001", "Análise e Desenvolvimento de Sistemas");

    // Criando disciplinas com construtor parametrizado
    Disciplina disciplina1("Programação Orientada a Objetos", 80, 7.5f);
    Disciplina disciplina2("Banco de Dados", 60, 4.8f);
    Disciplina disciplina3("Estruturas de Dados", 80, 6.0f);

    // Exibindo informações do aluno
    aluno.exibirInformacoes();

    std::cout << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "  Resultado por Disciplina" << std::endl;
    std::cout << "==============================" << std::endl;

    // Array de disciplinas para percorrer com loop
    Disciplina disciplinas[3] = {disciplina1, disciplina2, disciplina3};

    for (int i = 0; i < 3; i++) {
        std::cout << std::endl;
        std::cout << "Disciplina:    " << disciplinas[i].getNome() << std::endl;
        std::cout << "Carga Horária: " << disciplinas[i].getCargaHoraria() << "h" << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "Nota:          " << disciplinas[i].getNota() << std::endl;

        // Usando a função amiga para verificar aprovação
        if (verificarAprovacao(disciplinas[i])) {
            std::cout << "Situação:      APROVADO ✓" << std::endl;
        } else {
            std::cout << "Situação:      REPROVADO ✗" << std::endl;
        }
        std::cout << "------------------------------" << std::endl;
    }

    std::cout << std::endl;

    return 0;
}
