#include "Monitor.h"
#include <iostream>

// O construtor inicializa a classe base 'Usuario' explicitamente para evitar ambiguidade.
Monitor::Monitor(std::string nome, std::string email, std::string matricula, std::string curso, std::string areaAtuacao)
    : Usuario(nome, email, "Monitor"), 
      Aluno(nome, email, matricula, curso), 
      Professor(nome, email, areaAtuacao) {}

void Monitor::adicionarDisciplinaMonitorada(std::string disciplina) {
    disciplinasMonitoradas.push_back(disciplina);
}

void Monitor::listarDisciplinasMonitoradas() const {
    std::cout << "--- Disciplinas Monitoradas ---" << std::endl;
    for (const auto& d : disciplinasMonitoradas) {
        std::cout << "  - " << d << std::endl;
    }
    std::cout << "-----------------------------" << std::endl << std::endl;
}

// A sobrescrita de gerarRelatorio combina informações de Aluno e Professor.
void Monitor::gerarRelatorio() const {
    std::cout << "--- Relatorio de Monitor ---" << std::endl;
    std::cout << "Nome: " << nome << " (Atua como Aluno e assistente de Professor)" << std::endl;
    
    // Reutilizando a lógica da classe Aluno (simulado, pois os atributos são privados)
    // Para acesso direto, os atributos de Aluno/Professor poderiam ser 'protected'.
    // Por ora, vamos chamar os relatórios dos pais ou reimplementar.
    Aluno::gerarRelatorio();
    Professor::gerarRelatorio();
    listarDisciplinasMonitoradas();
}