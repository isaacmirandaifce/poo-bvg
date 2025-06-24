#include "Disciplina.h"

// Construtor padrão
Disciplina::Disciplina() {
    nome = "Não definida";
    cargaHoraria = 0;
    nota = 0.0;
}

// Construtor parametrizado
Disciplina::Disciplina(const std::string& nome, int cargaHoraria, float nota) {
    this->nome = nome;
    this->cargaHoraria = cargaHoraria;
    this->nota = nota;
}

// Setter da nota
void Disciplina::setNota(float novaNota) {
    nota = novaNota;
}

// Getter da nota
float Disciplina::getNota() const {
    return nota;
}

// Função amiga
void verificarAprovacao(const Disciplina& d) {
    std::cout << "Disciplina: " << d.nome << std::endl;
    std::cout << "Nota: " << d.nota << std::endl;
    if (d.nota >= 6.0) {
        std::cout << "Status: Aprovado ✅\n";
    } else {
        std::cout << "Status: Reprovado ❌\n";
    }
}
