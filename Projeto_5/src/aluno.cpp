#include "../include/Aluno.h"
#include <iostream>

// Construtor
Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& tipo, const std::string& curso)
    : Usuario(nome, email, tipo), curso(curso) {}

// Método para adicionar disciplina
void Aluno::adicionarDisciplina(const std::shared_ptr<Disciplina>& disciplina) {
    disciplinas.push_back(disciplina);
}

// Sobrescrita do método para gerar o relatório do aluno
void Aluno::gerarRelatorio() const {
    std::cout << "Relatorio do Aluno\n"
              << "Nome: " << nome << "\n"
              << "Email: " << email << "\n"
              << "Curso: " << curso << "\nDisciplinas:\n";

    for (const auto& disciplina : disciplinas) {
        disciplina->exibirInformacoes();
        std::cout << "---------------------\n";
    }
}

// Getter para disciplinas
const std::vector<std::shared_ptr<Disciplina>>& Aluno::getDisciplinas() const {
    return disciplinas;
}
