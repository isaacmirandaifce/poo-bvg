#include "Aluno.h"

Aluno::Aluno() : Usuario("", "", "Aluno"), matricula(""), curso(""), disciplinasCursadas() {
    tipo = "Aluno";
}

Aluno::Aluno(const std::string& nome,
             const std::string& email,
             const std::string& matricula,
             const std::string& curso,
             const std::vector<std::string>& disciplinasCursadas)
    : Usuario(nome, email, "Aluno"),
      matricula(matricula),
      curso(curso),
      disciplinasCursadas(disciplinasCursadas) {}

void Aluno::gerarRelatorio() const {
    std::cout << "===== RELATORIO (ALUNO) =====\n";
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Matricula: " << matricula << "\n";
    std::cout << "Curso: " << curso << "\n";
    std::cout << "Disciplinas cursadas:\n";
    for (const auto& d : disciplinasCursadas) {
        std::cout << " - " << d << "\n";
    }
    std::cout << "=============================\n\n";
}

void Aluno::exibirDetalhes() const {
    std::cout << "=== DETALHES DO ALUNO (SEM NOTAS) ===\n";
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Matricula: " << matricula << "\n";
    std::cout << "Curso: " << curso << "\n";
    std::cout << "Disciplinas:\n";
    for (const auto& d : disciplinasCursadas) {
        std::cout << " - " << d << "\n";
    }
    std::cout << "=====================================\n\n";
}

void Aluno::exibirDetalhes(const std::vector<float>& notas) const {
    std::cout << "=== DETALHES DO ALUNO (COM NOTAS) ===\n";
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Matricula: " << matricula << "\n";
    std::cout << "Curso: " << curso << "\n";

    std::cout << "Disciplinas e notas:\n";
    size_t n = disciplinasCursadas.size();
    for (size_t i = 0; i < n; i++) {
        std::cout << " - " << disciplinasCursadas[i] << " : ";
        if (i < notas.size()) std::cout << notas[i] << "\n";
        else std::cout << "(sem nota)\n";
    }
    std::cout << "====================================\n\n";
}

std::string Aluno::getMatricula() const { return matricula; }
std::string Aluno::getCurso() const { return curso; }
