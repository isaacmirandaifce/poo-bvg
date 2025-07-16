#include <iostream>
#include "src/Aluno/Aluno.h"
#include "src/Disciplina/Disciplina.h"

int main() {
    // Criando aluno
    Aluno aluno1("Ivan Magalhães", "20241234", "Análise e Desenvolvimento de Sistemas");

    // Criando disciplinas
    Disciplina d1("Programação Orientada a Objetos", 60);
    Disciplina d2("Banco de Dados", 60);

    // Definindo notas
    d1.setNota(10.0f);
    d2.setNota(5.0f);

    // Exibindo informações
    std::cout << "=== Informações do Aluno ===" << std::endl;
    aluno1.exibirInformacoes();

    std::cout << "\n=== Disciplinas ===" << std::endl;
    d1.exibirDados();
    verificarAprovacao(d1);

    std::cout << std::endl;

    d2.exibirDados();
    verificarAprovacao(d2);

    return 0;
}