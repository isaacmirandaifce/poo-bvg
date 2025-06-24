#include "Aluno.h"

Aluno::Aluno() : Usuario(), matricula("0000"), curso("Desconhecido") {}

Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {}

void Aluno::adicionarDisciplina(const std::string& disciplina) {
    disciplinas.push_back(disciplina);
}

void Aluno::gerarRelatorio() const {
    std::cout << "[Aluno] " << nome << " (" << matricula << ") - " << curso << std::endl;
    std::cout << "Disciplinas: ";
    for (const auto& d : disciplinas)
        std::cout << d << ", ";
    std::cout << "\n";
}

void Aluno::gerarRelatorio(bool mostrarNotas) const {
    gerarRelatorio();
    if (mostrarNotas) {
        std::cout << "[Notas fictícias] Ainda não implementadas.\n";
    }
}