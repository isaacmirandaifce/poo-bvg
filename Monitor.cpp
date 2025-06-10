#include "Monitor.h"

Monitor::Monitor(const std::string& nome, const std::string& email,
                 const std::string& matricula, const std::string& curso,
                 const std::vector<std::string>& disciplinasAluno,
                 const std::string& areaDeAtuacao, const std::vector<std::string>& disciplinasProfessor,
                 const std::vector<std::string>& disciplinasMonitoradas)
    : Aluno(nome, email, matricula, curso, disciplinasAluno),
      Professor(nome, email, areaDeAtuacao, disciplinasProfessor),
      disciplinasMonitoradas(disciplinasMonitoradas) 
{
    // Ajustar tipo para Monitor
    Aluno::tipo = "Monitor";
}

void Monitor::listarDisciplinasMonitoradas() const {
    std::cout << "Disciplinas Monitoradas por " << nome << ":\n";
    for (const auto& disc : disciplinasMonitoradas) {
        std::cout << "- " << disc << "\n";
    }
    std::cout << std::endl;
}

void Monitor::gerarRelatorio() const {
    std::cout << "Monitor: " << nome << "\nMatrícula: " << Aluno::matricula << "\nCurso: " << Aluno::curso << "\nÁrea de Atuação: " << Professor::areaDeAtuacao << "\n";
    
    std::cout << "Disciplinas Cursadas:\n";
    for (const auto& disc : Aluno::disciplinasCursadas) {
        std::cout << "- " << disc << "\n";
    }

    std::cout << "Disciplinas Ministradas:\n";
    for (const auto& disc : Professor::disciplinasMinistradas) {
        std::cout << "- " << disc << "\n";
    }

    listarDisciplinasMonitoradas();
}
