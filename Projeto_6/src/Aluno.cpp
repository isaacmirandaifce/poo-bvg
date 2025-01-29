#include "Aluno.h"
#include <iostream>
#include <sstream>

Aluno::HistoricoDisciplinar::HistoricoDisciplinar(const std::string& nomeDisciplina, int ano, float nota)
    : nomeDisciplina(nomeDisciplina), ano(ano), nota(nota) {}

std::string Aluno::HistoricoDisciplinar::getDetalhes() const {
    std::ostringstream oss;
    oss << nomeDisciplina << " - Ano: " << ano << " - Nota: " << nota;
    return oss.str();
}

Aluno::Aluno() : UsuarioAutenticavel(), matricula(""), curso("") {}

Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& senha,
             const std::string& matricula, const std::string& curso)
    : UsuarioAutenticavel(nome, email, senha), matricula(matricula), curso(curso) {}

void Aluno::adicionarDisciplina(const std::string& nomeDisciplina, int ano, float nota) {
    historico.emplace_back(nomeDisciplina, ano, nota);
}

bool Aluno::autenticar(const std::string& senha) const {
    return this->senha == senha;
}

void Aluno::exibirInformacoes() const {
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Matrícula: " << matricula << "\n";
    std::cout << "Curso: " << curso << "\n";
}

void Aluno::gerarRelatorio() const {
    std::cout << "Relatório do Aluno:\n";
    exibirInformacoes();
    std::cout << "Disciplinas cursadas:\n";
    for (const auto& disciplina : historico) {
        std::cout << "- " << disciplina.getDetalhes() << "\n";
    }
}