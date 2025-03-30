#include "../include/Monitor.h"
#include <iostream>

// Construtor
Monitor::Monitor(const std::string& nome, const std::string& email, const std::string& tipo, const std::string& curso)
    : Aluno(nome, email, tipo, curso) {}

// Adiciona uma disciplina monitorada
void Monitor::adicionarDisciplinaMonitorada(const std::shared_ptr<Disciplina>& disciplina) {
    disciplinasMonitoradas.push_back(disciplina);
}

// Sobrescrita do método para gerar o relatório do monitor
void Monitor::gerarRelatorio() const {
    std::cout << "Relatorio do Monitor\n"
              << "Nome: " << nome << "\n"
              << "Email: " << email << "\n"
              << "Curso: " << curso << "\nDisciplinas Cursadas:\n";

    for (const auto& disciplina : disciplinas) {
        disciplina->exibirInformacoes();
        std::cout << "---------------------\n";
    }

    std::cout << "Disciplinas Monitoradas:\n";
    for (const auto& disciplina : disciplinasMonitoradas) {
        disciplina->exibirInformacoes();
        std::cout << "---------------------\n";
    }
}
