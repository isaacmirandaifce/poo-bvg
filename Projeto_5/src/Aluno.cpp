#include "Aluno.h"
#include <iostream>

Aluno::Aluno() : Usuario(), matricula(""), curso("") {}

Aluno::Aluno(std::string n, std::string e, std::string t, std::string mat, std::string cur)
    : Usuario(n, e, t), matricula(mat), curso(cur) {}

void Aluno::adicionarDisciplina(std::string disc) {
    disciplinasCursadas.push_back(disc);
}

void Aluno::gerarRelatorio() {
    std::cout << "--- RELATORIO DE ALUNO ---" << std::endl;
    std::cout << "Nome: " << nome << " | Matricula: " << matricula << std::endl;
    std::cout << "Curso: " << curso << std::endl;
    std::cout << "Disciplinas Cursadas: ";
    for(const auto& d : disciplinasCursadas) std::cout << "[" << d << "] ";
    std::cout << "\n--------------------------" << std::endl;
}

// Sobrecarga 1: Sem notas
void Aluno::exibirInformacoesDetalhadas() {
    std::cout << "[Detalhado] Aluno " << nome << " matriculado em " << curso << " sem notas registradas." << std::endl;
}

// Sobrecarga 2: Com notas
void Aluno::exibirInformacoesDetalhadas(const std::vector<double>& notas) {
    std::cout << "[Detalhado] Aluno " << nome << " | Notas: ";
    double soma = 0;
    for(double nota : notas) {
        std::cout << nota << " ";
        soma += nota;
    }
    if(!notas.empty()) std::cout << "| Media: " << (soma / notas.size());
    std::cout << std::endl;
}