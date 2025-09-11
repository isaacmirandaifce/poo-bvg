#include "Professor.h"
#include <iostream>

Professor::Professor(const std::string& nome, const std::string& email, const std::string& senha, const std::string& disciplina)
    : UsuarioAutenticavel(nome, email, senha), disciplina(disciplina), tipo(TipoUsuario::PROFESSOR) {}

bool Professor::autenticar(const std::string& tentativaSenha) const {
    return senha == tentativaSenha;
}

void Professor::gerarRelatorio() const {
    std::cout << "Relatório do Professor\n";
    std::cout << "Nome: " << nome << "\nEmail: " << email << "\nDisciplina: " << disciplina << "\n";
}

TipoUsuario Professor::getTipo() const {
    return tipo;
}

std::string Professor::getDisciplina() const {
    return disciplina;
}

void Professor::setDisciplina(const std::string& novaDisciplina) {
    disciplina = novaDisciplina;
}