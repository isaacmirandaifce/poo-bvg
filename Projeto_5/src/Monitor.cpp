#include "Monitor.h"
#include <iostream>

Monitor::Monitor()
    : Usuario("", "", "Monitor"),
      Aluno(),
      Professor(),
      disciplinasMonitoradas() {
    tipo = "Monitor";
}

Monitor::Monitor(const std::string& nome,
                 const std::string& email,
                 const std::string& matricula,
                 const std::string& curso,
                 const std::vector<std::string>& disciplinasCursadas,
                 const std::string& areaDeAtuacao,
                 const std::vector<std::string>& disciplinasMinistradas,
                 const std::vector<std::string>& disciplinasMonitoradas)
    : Usuario(nome, email, "Monitor"),
      Aluno(nome, email, matricula, curso, disciplinasCursadas),
      Professor(nome, email, areaDeAtuacao, disciplinasMinistradas),
      disciplinasMonitoradas(disciplinasMonitoradas) {
    tipo = "Monitor";
}

void Monitor::listarDisciplinasMonitoradas() const {
    std::cout << "Disciplinas monitoradas por " << nome << ":\n";
    for (const auto& d : disciplinasMonitoradas) {
        std::cout << " - " << d << "\n";
    }
    std::cout << "\n";
}

void Monitor::gerarRelatorio() const {
    std::cout << "===== RELATORIO (MONITOR) =====\n";
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Matricula: " << matricula << "\n";
    std::cout << "Curso: " << curso << "\n";
    std::cout << "Area de atuacao: " << areaDeAtuacao << "\n";

    std::cout << "Disciplinas cursadas:\n";
    for (const auto& d : disciplinasCursadas) std::cout << " - " << d << "\n";

    std::cout << "Disciplinas ministradas:\n";
    for (const auto& d : disciplinasMinistradas) std::cout << " - " << d << "\n";

    std::cout << "Disciplinas monitoradas:\n";
    for (const auto& d : disciplinasMonitoradas) std::cout << " - " << d << "\n";

    std::cout << "==============================\n\n";
}
