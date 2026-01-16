#include "Aluno.h"
#include <iostream>

// Construtor padrão: inicializa atributos vazios
Aluno::Aluno() : Usuario(), matricula(""), curso("") {}

// Construtor com parâmetros: recebe nome, email, matrícula e curso
// Passa "Aluno" como tipo de usuário para o construtor da classe base Usuario
Aluno::Aluno(const std::string& nome,
             const std::string& email,
             const std::string& matricula,
             const std::string& curso)
    : Usuario(nome, email, "Aluno"), // chama o construtor da classe base
      matricula(matricula),
      curso(curso) {}

// Exibe relatório básico do aluno
void Aluno::gerarRelatorio() const {
    std::cout << "Nome: " << nome
              << "\nMatrícula: " << matricula
              << "\nCurso: " << curso
              << std::endl;
}

// Exibe informações do aluno, com opção de incluir as disciplinas cursadas
void Aluno::exibirInformacoes(bool comNotas) const {
    gerarRelatorio(); // Exibe dados principais

    // Se comNotas for verdadeiro, exibe as disciplinas cursadas
    if (comNotas) {
        std::cout << "Disciplinas Cursadas: " << std::endl;
        for (const auto& disciplina : disciplinasCursadas) {
            std::cout << " - " << disciplina << std::endl;
        }
    }
}

// Adiciona uma nova disciplina ao vetor de disciplinas cursadas pelo aluno
void Aluno::adicionarDisciplina(const std::string& disciplina) {
    disciplinasCursadas.push_back(disciplina);
}