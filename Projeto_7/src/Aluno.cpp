#include "Aluno.h"
#include <iostream>

Aluno::Aluno(const std::string& nome,
             const std::string& email,
             const std::string& senha,
             double media)
    : UsuarioAutenticavel(nome, email, TipoUsuario::ALUNO, senha),
      media(media) {}

bool Aluno::autenticar(const std::string& senhaInformada) const {
    return senha == senhaInformada;
}

void Aluno::gerarRelatorio() const {
    std::cout << "Aluno: " << nome << " | Média: " << media << std::endl;
}

double Aluno::getMedia() const {
    return media;
}