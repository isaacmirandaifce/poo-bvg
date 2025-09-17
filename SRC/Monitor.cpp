#include "Monitor.h"
#include <iostream>

Monitor::Monitor(const std::string& nome, const std::string& email,
                 const std::string& matricula, const std::string& departamento)
    : Aluno(nome, email, matricula), 
      Professor(nome, email, departamento) {
    tipo = "Monitor"; // Corrige o tipo
}

void Monitor::exibirInformacoes() const {
    std::cout << "Monitor: " << Aluno::getNome() << "\n";
    std::cout << "Matrícula: " << getMatricula() << "\n";
    std::cout << "Departamento: " << Professor::getDepartamento() << "\n";
    std::cout << "Email: " << Aluno::getEmail() << "\n";
    std::cout << "Disciplinas monitoradas: " << disciplinasMonitoradas.size() << "\n";
}

void Monitor::adicionarDisciplinaMonitorada(const std::string& codigoDisciplina) {
    disciplinasMonitoradas.push_back(codigoDisciplina);
}

void Monitor::listarDisciplinasMonitoradas() const {
    std::cout << "Disciplinas monitoradas por " << Aluno::getNome() << ":\n";
    for (const auto& disc : disciplinasMonitoradas) {
        std::cout << " - " << disc << "\n";
    }
}