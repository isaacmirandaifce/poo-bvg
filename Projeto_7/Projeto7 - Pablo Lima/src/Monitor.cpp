#include "Monitor.h"

// Construtor padrão
Monitor::Monitor() : Aluno(), Professor() {}

// Construtor parametrizado
Monitor::Monitor(const std::string& nome, const std::string& email, const std::string& matricula,
                 const std::string& curso, const std::string& areaDeAtuacao)
    : Aluno(nome, email, matricula, curso), Professor(nome, email, areaDeAtuacao) {}

// Adicionar disciplina monitorada
void Monitor::adicionarDisciplinaMonitorada(const std::string& disciplina) {
    disciplinasMonitoradas.push_back(disciplina);
}

// Sobrescrita do método gerarRelatorio
void Monitor::gerarRelatorio() const {
    std::cout << "Relatório do Monitor\n";
    std::cout << "Nome: " << nome << "\n"
              << "Curso: " << curso << "\n"
              << "Área de Atuação: " << areaDeAtuacao << "\n"
              << "Disciplinas Monitoradas:\n";
    for (const auto& disciplina : disciplinasMonitoradas) {
        std::cout << " - " << disciplina << "\n";
    }
}
