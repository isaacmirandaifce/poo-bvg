#include "Monitor.hpp"
#include <iostream>

Monitor::Monitor() : Usuario(), Aluno(), Professor() {
    this->tipo = "Monitor";
}

Monitor::Monitor(const std::string& nome, const std::string& email,
                 const std::string& matricula, const std::string& curso,
                 const std::string& areaDeAtuacao)
    : Usuario(nome, email, "Monitor"),
      Aluno(nome, email, matricula, curso),
      Professor(nome, email, areaDeAtuacao) {}

void Monitor::adicionarDisciplinaAluno(const std::string& disciplina) {
    Aluno::adicionarDisciplina(disciplina);
}

void Monitor::adicionarDisciplinaProfessor(const std::string& disciplina) {
    Professor::adicionarDisciplina(disciplina);
}

void Monitor::adicionarDisciplinaMonitorada(const std::string& disciplina) {
    disciplinasMonitoradas.push_back(disciplina);
}

void Monitor::listarDisciplinasMonitoradas() const {
    std::cout << "Disciplinas Monitoradas:\n";
    for (const auto& d : disciplinasMonitoradas) {
        std::cout << "- " << d << "\n";
    }
}

void Monitor::gerarRelatorio() const {
    std::cout << "Relatorio do Monitor\n";
    std::cout << "Nome: " << Aluno::nome << "\n";
    std::cout << "Matricula: " << Aluno::matricula << "\n";
    std::cout << "Curso: " << Aluno::curso << "\n";
    std::cout << "Area de Atuacao: " << Professor::getAreaDeAtuacao() << "\n";
    listarDisciplinasMonitoradas();
    std::cout << "----------------------\n";
}
