#include "Aluno.h"
#include <iostream>

Aluno::aluno() {}

// Construtor com inicialização da classe base Usuario
Aluno::Aluno(std::string nome, std::string email, std::string matricula, std::string curso)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {}

void Aluno::adicionarDisciplina(std::string d) {
    disciplinas.push_back(d);
}

// classe Aluno sobrescreve o método virtual puro gerarRelatorio
void Aluno::gerarRelatorio() const {
    std::cout << "\n=== Relatório do Aluno ===\n";
    std::cout << "Nome: " << nome << "\nEmail: " << email;
    std::cout << "\nMatrícula: " << matricula << "\nCurso: " << curso << "\n";
    std::cout << "Disciplinas: ";
    for (auto &d : disciplinas) std::cout << d << ", ";
    std::cout << "\n";
}


// Sobrecarga do método exibirInfo
void Aluno::exibirInfo() const {
    std::cout << nome << " - " << curso << "\n";
}

// Sobrecarga do método exibirInfo com parâmetro
void Aluno::exibirInfo(bool mostrarNotas) const {
    std::cout << nome << " - " << curso << "\n";
    if (mostrarNotas)
        std::cout << "(Notas não implementadas, apenas exemplo de sobrecarga)\n";
}
