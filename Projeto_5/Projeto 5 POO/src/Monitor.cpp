#include "Monitor.h"
#include <iostream>

Monitor::Monitor()
    : Usuario("", "", "Monitor"),
      Aluno("", "", "", ""),
      Professor("", "", "", std::vector<std::string>()),
      disciplinasMonitoradas() {}

Monitor::Monitor(const std::string& nome,
                 const std::string& email,
                 const std::string& matricula,
                 const std::string& curso,
                 const std::string& areaDeAtuacao,
                 const std::vector<std::string>& disciplinasMinistradas,
                 const std::vector<std::string>& disciplinasMonitoradas)
    : Usuario(nome, email, "Monitor"),
      Aluno(nome, email, matricula, curso),
      Professor(nome, email, areaDeAtuacao, disciplinasMinistradas),
      disciplinasMonitoradas(disciplinasMonitoradas) {}

void Monitor::gerarRelatorio() const {
    std::cout << "[Monitor] Nome: " << nome
              << " | Matrícula: " << getMatricula()
              << " | Curso: " << getCurso() << std::endl;

    listarDisciplinasMonitoradas();
}

void Monitor::listarDisciplinasMonitoradas() const {
    if (disciplinasMonitoradas.empty()) {
        std::cout << "Nenhuma disciplina monitorada no momento." << std::endl;
        return;
    }

    std::cout << "Disciplinas monitoradas:" << std::endl;
    for (const auto& d : disciplinasMonitoradas) {
        std::cout << "- " << d << std::endl;
    }
}
