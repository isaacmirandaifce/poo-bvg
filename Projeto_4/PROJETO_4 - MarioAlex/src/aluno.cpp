#include "Aluno.h"

// Construtor padrão
Aluno::Aluno() {
    nome = "Desconhecido";
    matricula = "0000";
    curso = "Não definido";
}

// Construtor parametrizado
Aluno::Aluno(const std::string& nome, const std::string& matricula, const std::string& curso) {
    this->nome = nome;
    this->matricula = matricula;
    this->curso = curso;
}

// Exibir informações
void Aluno::exibirInformacoes() const {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Matrícula: " << matricula << std::endl;
    std::cout << "Curso: " << curso << std::endl;
}
