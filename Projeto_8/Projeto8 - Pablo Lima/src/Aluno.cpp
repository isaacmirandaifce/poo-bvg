#include "Aluno.h"
#include <iostream>

Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& senha, const std::string& curso, double media)
    : UsuarioAutenticavel(nome, email, senha), curso(curso), media(media) {}

void Aluno::gerarRelatorio() const {
    std::cout << "Aluno: " << nome << "\nCurso: " << curso << "\nMédia: " << media << "\n";
}

bool Aluno::autenticar(const std::string& senha) {
    return senha == this->senha;
}