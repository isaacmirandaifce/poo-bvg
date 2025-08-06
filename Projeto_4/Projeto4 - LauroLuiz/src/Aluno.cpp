#include "Aluno.h"

// Construtor padrão
Aluno::Aluno() : nome(""), matricula(""), curso("") {
}

// Construtor parametrizado
Aluno::Aluno(const std::string& nome, const std::string& matricula, const std::string& curso)
    : nome(nome), matricula(matricula), curso(curso) {
}

// Destructor
Aluno::~Aluno() {
}

// Getters
std::string Aluno::getNome() const {
    return nome;
}

std::string Aluno::getMatricula() const {
    return matricula;
}

std::string Aluno::getCurso() const {
    return curso;
}

// Setters
void Aluno::setNome(const std::string& nome) {
    this->nome = nome;
}

void Aluno::setMatricula(const std::string& matricula) {
    this->matricula = matricula;
}

void Aluno::setCurso(const std::string& curso) {
    this->curso = curso;
}

// Método para exibir informações do aluno
void Aluno::exibirInformacoes() const {
    std::cout << "========================================" << std::endl;
    std::cout << "           INFORMAÇÕES DO ALUNO         " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Matrícula: " << matricula << std::endl;
    std::cout << "Curso: " << curso << std::endl;
    std::cout << "========================================" << std::endl;
}