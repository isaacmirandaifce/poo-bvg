#include "Disciplina.h"

Disciplina::Disciplina(const std::string& nome, int ano) : nome(nome), ano(ano) {}

const std::string& Disciplina::getNome() const {
    return nome;
}

int Disciplina::getAno() const {
    return ano;
}

void Disciplina::imprimir() const {
    std::cout << "Disciplina: " << nome << " | Ano: " << ano << std::endl;
}
