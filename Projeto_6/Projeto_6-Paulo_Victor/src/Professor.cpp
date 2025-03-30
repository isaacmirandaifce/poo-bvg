#include "Professor.h"
#include <iostream>

Professor::Professor(std::string nome, std::string areaDeAtuacao, std::string senha)
    : UsuarioAutenticavel(senha), nome(nome), areaDeAtuacao(areaDeAtuacao), tipo(TipoUsuario::PROFESSOR) {}

bool Professor::autenticar(std::string senha) const {
    return this->senha == senha;
}

void Professor::gerarRelatorio() const {
    std::cout << "Relatório do Professor:\n";
    std::cout << "Nome: " << nome << "\nArea de Atuação: " << areaDeAtuacao << "\n";
    std::cout << "Disciplinas Ministradas:\n";
    for (const auto& disciplina : disciplinasMinistradas) {
        std::cout << "- " << disciplina << "\n";
    }
}

void Professor::adicionarDisciplinaMinistrada(std::string disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}