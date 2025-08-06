#include "Disciplina.h"
#include <iomanip>

// Construtor padrão
Disciplina::Disciplina() : nome(""), cargaHoraria(0), nota(0.0f) {
}

// Construtor parametrizado (sem nota)
Disciplina::Disciplina(const std::string& nome, int cargaHoraria)
    : nome(nome), cargaHoraria(cargaHoraria), nota(0.0f) {
}

// Construtor parametrizado (com nota)
Disciplina::Disciplina(const std::string& nome, int cargaHoraria, float nota)
    : nome(nome), cargaHoraria(cargaHoraria), nota(nota) {
}

// Destructor
Disciplina::~Disciplina() {
}

// Getters
std::string Disciplina::getNome() const {
    return nome;
}

int Disciplina::getCargaHoraria() const {
    return cargaHoraria;
}

float Disciplina::getNota() const {
    return nota;
}

// Setters
void Disciplina::setNome(const std::string& nome) {
    this->nome = nome;
}

void Disciplina::setCargaHoraria(int cargaHoraria) {
    if (cargaHoraria >= 0) {
        this->cargaHoraria = cargaHoraria;
    } else {
        std::cout << "Erro: Carga horária deve ser positiva!" << std::endl;
    }
}

void Disciplina::setNota(float nota) {
    if (nota >= 0.0f && nota <= 10.0f) {
        this->nota = nota;
    } else {
        std::cout << "Erro: Nota deve estar entre 0 e 10!" << std::endl;
    }
}

// Método para exibir informações da disciplina
void Disciplina::exibirInformacoes() const {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Disciplina: " << nome << std::endl;
    std::cout << "Carga Horária: " << cargaHoraria << " horas" << std::endl;
    std::cout << "Nota: " << std::fixed << std::setprecision(1) << nota << std::endl;
    std::cout << "Status: " << (verificarAprovacao(*this) ? "APROVADO" : "REPROVADO") << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

// Implementação da função amiga para verificar aprovação
bool verificarAprovacao(const Disciplina& disciplina) {
    // Acesso direto ao atributo privado 'nota' através da função amiga
    return disciplina.nota >= 6.0f;
}

// Implementação da função amiga para validar critérios de aprovação
bool validarCriteriosAprovacao(const Disciplina& disciplina, float notaMinima) {
    // Acesso direto aos atributos privados através da função amiga
    return disciplina.nota >= notaMinima && disciplina.cargaHoraria > 0;
}