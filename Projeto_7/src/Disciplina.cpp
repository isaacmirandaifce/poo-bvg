#include "Disciplina.h"
#include <iostream>

Disciplina::Disciplina(const std::string& nome, const std::string& codigo, int ano)
    : nome(nome), codigo(codigo), ano(ano) {}

std::string Disciplina::getNome() const {
    return nome;
}

std::string Disciplina::getCodigo() const {
    return codigo;
}

int Disciplina::getAno() const {
    return ano;
}

void Disciplina::imprimir() const {
    std::cout << "Disciplina: " << nome << " (Codigo: " << codigo << ", Ano: " << ano << ")" << std::endl;
}