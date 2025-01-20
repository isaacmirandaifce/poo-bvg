#include "../include/Aluno.h"

Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {}

void Aluno::adicionarDisciplina(const std::string& disciplina) {
    disciplinas.push_back(disciplina);
}

void Aluno::gerarRelatorio() const {
    std::cout << "Relatorio do Aluno\n";
    std::cout << "Nome: " << nome << "\nMatricula: " << matricula
              << "\nCurso: " << curso << "\nDisciplinas Cursadas:\n";
    for (const auto& disciplina : disciplinas) {
        std::cout << "- " << disciplina << "\n";
    }
}

void Aluno::gerarRelatorio(bool exibirNotas) const {
    gerarRelatorio(); // Chama o método base
    if (exibirNotas) {
        std::cout << "(Notas podem ser exibidas aqui...)\n";
    }
}
