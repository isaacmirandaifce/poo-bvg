#include "Professor.h"
#include <iostream>

Professor::Professor(std::string nome, std::string areaDeAtuacao, std::string senha)
    : UsuarioAutenticavel(senha), nome(nome), areaDeAtuacao(areaDeAtuacao), tipo(TipoUsuario::PROFESSOR) {}

bool Professor::autenticar(std::string senha) const {
    return this->senha == senha;
}

void Professor::gerarRelatorio() const {
    std::cout << "Relatorio do Professor:\n";
    std::cout << "Nome: " << nome << "\nArea de Atuacao: " << areaDeAtuacao << "\n";
}

void Professor::adicionarDisciplinaMinistrada(std::string disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

std::string Professor::getDisciplina() const {
    return areaDeAtuacao;
}

void Professor::exibirInformacoes() const {
    std::cout << "Nome: " << nome << ", Area de Atuacao: " << areaDeAtuacao << "\n";
}