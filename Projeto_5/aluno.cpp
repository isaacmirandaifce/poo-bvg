#include "Aluno.h"
#include <iostream>

Aluno::Aluno() : Usuario(), matricula(""), curso("") {}

Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {}

void Aluno::adicionarDisciplina(const std::string& disciplina) {
    disciplinas.push_back(disciplina);
}

void Aluno::gerarRelatorio() const {
    std::cout << "Relatório do Aluno\n";
    std::cout << "Nome: " << nome << "\nEmail: " << email << "\nCurso: " << curso << "\n";
    std::cout << "Disciplinas: ";
    for (const auto& disc : disciplinas)
        std::cout << disc << " ";
    std::cout << "\n";
}

void Aluno::gerarRelatorio(bool incluirNotas) const {
    gerarRelatorio(); 
    if (incluirNotas) {
        std::cout << "(Detalhes adicionais seriam implementados aqui)\n";
    }
}
