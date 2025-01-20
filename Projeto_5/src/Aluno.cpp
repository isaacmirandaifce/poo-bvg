#include "Aluno.h"

Aluno::Aluno() : Usuario(), matricula(""), curso("") {}

Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {}

void Aluno::adicionarDisciplina(const std::string& disciplina) {
    disciplinas.push_back(disciplina);
}

void Aluno::gerarRelatorio() const {
    std::cout << "Relatório do Aluno:" << std::endl;
    std::cout << "Nome: " << nome << ", Matrícula: " << matricula << ", Curso: " << curso << std::endl;
    std::cout << "Disciplinas cursadas: ";
    for (const auto& disc : disciplinas) {
        std::cout << disc << " ";
    }
    std::cout << std::endl;
}

void Aluno::exibirInformacoes(bool incluirNotas) const {
    std::cout << "Nome: " << nome << ", Matrícula: " << matricula << ", Curso: " << curso << std::endl;
    if (incluirNotas) {
        std::cout << "Notas: (funcionalidade a implementar)" << std::endl;
    }
}
