#include "Monitor.h"

Monitor::Monitor() : Aluno(), Professor() {}

Monitor::Monitor(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso, const std::string& areaDeAtuacao)
    : Usuario(nome, email, "Monitor"), Aluno(nome, email, matricula, curso), Professor(nome, email, areaDeAtuacao) {}

void Monitor::adicionarDisciplina(const std::string& disciplina) {
    Aluno::adicionarDisciplina(disciplina); // Usa o método de Aluno
}

void Monitor::adicionarDisciplinaMonitorada(const std::string& disciplina) {
    disciplinasMonitoradas.push_back(disciplina);
}

void Monitor::gerarRelatorio() const {
    std::cout << "Relatório do Monitor:" << std::endl;
    std::cout << "Nome: " << nome << ", Matrícula: " << matricula << ", Curso: " << curso << std::endl;
    std::cout << "Área de Atuação: " << areaDeAtuacao << std::endl;
    std::cout << "Disciplinas Monitoradas: ";
    for (const auto& disc : disciplinasMonitoradas) {
        std::cout << disc << " ";
    }
    std::cout << std::endl;
}
