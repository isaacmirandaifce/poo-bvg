#include "Aluno.h"
#include <iostream>

Aluno::Aluno(std::string nome, std::string email, std::string matricula, std::string curso)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {}

// Implementação da sobrescrita de gerarRelatorio.
void Aluno::gerarRelatorio() const {
    std::cout << "--- Relatorio de Aluno ---" << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Matricula: " << matricula << std::endl;
    std::cout << "Curso: " << curso << std::endl;
    std::cout << "Disciplinas Cursadas: ";
    for (const auto& d : disciplinasCursadas) {
        std::cout << d << " ";
    }
    std::cout << "\n--------------------------" << std::endl << std::endl;
}

void Aluno::adicionarDisciplina(std::string disciplina) {
    disciplinasCursadas.push_back(disciplina);
}

// Implementação dos métodos sobrecarregados. 
void Aluno::exibirInformacoesDetalhadas() const {
    exibirInformacoesDetalhadas(false); // Chama a outra versão por padrão, sem notas.
}

void Aluno::exibirInformacoesDetalhadas(bool comNotas) const {
    std::cout << "--- Informacoes Detalhadas do Aluno ---" << std::endl;
    std::cout << "Nome: " << nome << " | Email: " << email << std::endl;
    std::cout << "Matricula: " << matricula << " | Curso: " << curso << std::endl;

    if (comNotas) {
        std::cout << "Notas (Exemplo): " << std::endl;
        for (const auto& d : disciplinasCursadas) {
            std::cout << "  - " << d << ": 8.5" << std::endl;
        }
    }
    std::cout << "---------------------------------------" << std::endl << std::endl;
}