#include "aluno.h"
#include <iostream>

Aluno::Aluno()
    : UsuarioAutenticavel(), matricula(""), curso(""), tipoUsuario(TipoUsuario::ALUNO) {}

Aluno::Aluno(std::string nome, std::string email, std::string senha,
             std::string matricula, std::string curso)
    : UsuarioAutenticavel(nome, email, "Aluno", senha),
      matricula(matricula), curso(curso), tipoUsuario(TipoUsuario::ALUNO) {}

void Aluno::adicionarDisciplinaHistorico(std::string nome, int ano, float nota) {
    historico.emplace_back(nome, ano, nota);
}

void Aluno::gerarRelatorio() const {
    std::cout << "=== Relatório do Aluno ===\n";
    std::cout << "Nome: " << nome << "\nEmail: " << email
              << "\nCurso: " << curso << "\nMatrícula: " << matricula << "\n";

    std::cout << "--- Histórico Disciplinar ---\n";
    for (const auto& h : historico) {
        std::cout << h.ano << " - " << h.nomeDisciplina << " | Nota: " << h.nota << "\n";
    }
}

void Aluno::exibirInformacoes(bool comNotas) const {
    std::cout << "Aluno: " << nome << " - Curso: " << curso << "\n";
    if (comNotas) {
        std::cout << "Notas por disciplina:\n";
        for (const auto& h : historico) {
            std::cout << h.nomeDisciplina << ": " << h.nota << "\n";
        }
    }
}

bool Aluno::autenticar(std::string senhaDigitada) const {
    return senhaDigitada == senha;
}