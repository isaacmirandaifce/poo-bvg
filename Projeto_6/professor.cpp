#include "Professor.h"
#include <iostream>

Professor::Professor(const std::string& nome, const std::string& email, const std::string& areaDeAtuacao, const std::string& senha)
    : UsuarioAutenticavel(nome, email, "PROFESSOR", senha), areaDeAtuacao(areaDeAtuacao) {}

void Professor::adicionarDisciplina(const std::string& disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void Professor::gerarRelatorio() const {
    std::cout << "Relatório do Professor\n";
    std::cout << "Nome: " << nome << "\nEmail: " << email << "\nÁrea de Atuação: " << areaDeAtuacao << "\n";
    std::cout << "Disciplinas Ministradas: ";
    for (const auto& disc : disciplinasMinistradas) {
        std::cout << disc << " ";
    }
    std::cout << "\n";
}

bool Professor::autenticar(const std::string& senhaTentativa) {
    return senhaTentativa == senha;
}