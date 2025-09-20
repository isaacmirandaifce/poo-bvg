#include "Aluno.h"
#include <iostream>

Aluno::Aluno(std::string nome, std::string email, std::string matricula, std::string curso)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {
    // O corpo pode ficar vazio, pois toda a inicialização foi feita na lista de inicializadores.
}

// Implementação da sobrescrita de gerarRelatorio()
void Aluno::gerarRelatorio() {
    std::cout << "--- Relatório do Aluno ---" << std::endl;
    std::cout << "Nome: " << this->nome << std::endl; // 'nome' é acessível pois é 'protected'
    std::cout << "Matrícula: " << this->matricula << std::endl;
    std::cout << "Curso: " << this->curso << std::endl;
    std::cout << "Disciplinas Cursadas:" << std::endl;
    if (disciplinasCursadas.empty()) {
        std::cout << "  Nenhuma disciplina cursada." << std::endl;
    } else {
        for (const std::string& disciplina : disciplinasCursadas) {
            std::cout << "  - " << disciplina << std::endl;
        }
    }
}

// Implementação da sobrecarga de gerarRelatorio(bool comNotas)
void Aluno::gerarRelatorio(bool comNotas) {
    if (comNotas) {
        // Se comNotas for true, exibe o relatório padrão e adiciona as notas
        gerarRelatorio(); // Reutiliza o código do relatório base
        std::cout << "Notas:" << std::endl;
        std::cout << "  - Cálculo I: 8.5" << std::endl;
        std::cout << "  - Algoritmos: 9.0" << std::endl;
        // (As notas são fixas aqui apenas para demonstração)
    } else {
        // Se comNotas for false, chama a versão original sem notas
        gerarRelatorio();
    }
}

void Aluno::adicionarDisciplina(const std::string& disciplina) {
    this->disciplinasCursadas.push_back(disciplina);
}
