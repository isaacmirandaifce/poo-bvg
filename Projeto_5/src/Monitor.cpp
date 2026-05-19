#include "Monitor.h"
#include <iostream>


Monitor::Monitor(std::string n, std::string e, std::string t, std::string mat, std::string cur, std::string area, std::vector<std::string> discMin)
    : Usuario(n, e, t), Aluno(n, e, t, mat, cur), Professor(n, e, t, area, discMin) {}

void Monitor::adicionarMonitoria(std::string disc) {
    disciplinasMonitoradas.push_back(disc);
}

void Monitor::listarDisciplinasMonitoradas() {
    std::cout << "Disciplinas Monitoradas por " << nome << ": ";
    for(const auto& d : disciplinasMonitoradas) std::cout << "<" << d << "> ";
    std::cout << std::endl;
}

void Monitor::gerarRelatorio() {
    std::cout << "--- RELATORIO DE MONITOR (HERANCA MULTIPLA) ---" << std::endl;
    std::cout << "Nome: " << nome << " | Email: " << email << std::endl;
    std::cout << "Matricula: " << matricula << " | Curso: " << curso << std::endl;
    std::cout << "Area de Atuacao: " << areaDeAtuacao << std::endl;
    listarDisciplinasMonitoradas();
    std::cout << "-----------------------------------------------" << std::endl;
}