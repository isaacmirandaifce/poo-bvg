#include "../include/Aluno.h"
#include <iostream>

Aluno::Aluno() : UsuarioAutenticavel(), matricula(""), curso("") {}

Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso, const std::string& senha)
    : UsuarioAutenticavel(nome, email, "ALUNO", senha), matricula(matricula), curso(curso) {}

bool Aluno::autenticar(const std::string& senha) const {
    return verificarSenha(senha); // Usa o método protegido da classe base
}

void Aluno::gerarRelatorio() const {
    std::cout << "Relatório do Aluno:\n"
              << "Nome: " << nome << "\n"
              << "Matrícula: " << matricula << "\n"
              << "Curso: " << curso << "\n"
              << "Histórico Disciplinar:\n";
    for (const auto& h : historico) {
        h.exibirHistorico();
    }
}

void Aluno::adicionarHistorico(const HistoricoDisciplinar& h) {
    historico.push_back(h);
}

void Aluno::HistoricoDisciplinar::exibirHistorico() const {
    std::cout << " - Disciplina: " << nomeDisciplina << ", Ano: " << anoCursado << ", Nota: " << nota << "\n";
}


