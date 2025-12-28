#include "Disciplina.h"

Disciplina::Disciplina() : nome(""), ano(0) {}

Disciplina::Disciplina(std::string nome, int ano)
    : nome(nome), ano(ano) {}

std::string Disciplina::getNome() const {
    return nome;
}

int Disciplina::getAno() const {
    return ano;
}
