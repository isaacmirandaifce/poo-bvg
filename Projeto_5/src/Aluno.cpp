#include "Aluno.h"
#include <iostream>

Aluno::Aluno() : Usuario(), matricula(""), curso("") {}

Aluno::Aluno(std::string nome, std::string email, std::string matricula, std::string curso)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {}

void Aluno::adicionarDisciplina(const std::string& disciplina) {
    disciplinas.push_back(disciplina);
}

void Aluno::gerarRelatorio() const {
    std::cout << "Relatório do Aluno:\n"
              << "Nome: " << nome << "\n"
              << "Matrícula: " << matricula << "\n"
              << "Curso: " << curso << "\n"
              << "Disciplinas: ";
    for (const auto& disc : disciplinas)
        std::cout << disc << " ";
    std::cout << "\n";
}

void Aluno::exibirDetalhes(bool comNotas) {
    gerarRelatorio();
    if (comNotas) {
        std::cout << "Notas: [Simuladas: 8.0, 7.5, 9.0]\n";
    }
}
