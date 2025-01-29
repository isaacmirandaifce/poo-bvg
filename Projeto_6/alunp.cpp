#include "Aluno.h"
#include <iostream>

Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso, const std::string& senha)
    : UsuarioAutenticavel(nome, email, "ALUNO", senha), matricula(matricula), curso(curso) {}

void Aluno::adicionarDisciplina(const std::string& disciplina) {
    disciplinas.push_back(disciplina);
}

void Aluno::gerarRelatorio() const {
    std::cout << "Relatório do Aluno\n";
    std::cout << "Nome: " << nome << "\nEmail: " << email << "\nCurso: " << curso << "\n";
    std::cout << "Disciplinas: ";
    for (const auto& disc : disciplinas) {
        std::cout << disc << " ";
    }
    std::cout << "\n";
}

bool Aluno::autenticar(const std::string& senhaTentativa) {
    return senhaTentativa == senha;
}