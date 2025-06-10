#include "Aluno.h"

Aluno::Aluno()
    : Usuario(), matricula(""), curso(""), disciplinasCursadas(), notas() {}

Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& matricula,
             const std::string& curso, const std::vector<std::string>& disciplinas)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso), disciplinasCursadas(disciplinas) {}

void Aluno::gerarRelatorio() const {
    std::cout << "Aluno: " << nome << "\nMatrícula: " << matricula << "\nCurso: " << curso << "\nDisciplinas Cursadas:\n";
    for (const auto& disc : disciplinasCursadas) {
        std::cout << "- " << disc << "\n";
    }
    std::cout << std::endl;
}

void Aluno::gerarRelatorio(const std::vector<float>& notas) const {
    std::cout << "Aluno: " << nome << "\nMatrícula: " << matricula << "\nCurso: " << curso << "\nDisciplinas e Notas:\n";
    size_t count = std::min(disciplinasCursadas.size(), notas.size());
    for (size_t i = 0; i < count; ++i) {
        std::cout << "- " << disciplinasCursadas[i] << ": " << notas[i] << "\n";
    }
    std::cout << std::endl;
}
