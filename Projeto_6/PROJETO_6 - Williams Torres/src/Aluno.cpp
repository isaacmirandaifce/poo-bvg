#include "Aluno.h"
#include <sstream>

// HistoricoDisciplinar
Aluno::HistoricoDisciplinar::HistoricoDisciplinar(const std::string& nomeDisciplina, int ano, float nota)
    : nomeDisciplina(nomeDisciplina), ano(ano), nota(nota) {}

std::string Aluno::HistoricoDisciplinar::getDetalhes() const {
    std::ostringstream oss;
    oss << nomeDisciplina << " - Ano: " << ano << " - Nota: " << nota;
    return oss.str();
}

// Aluno
Aluno::Aluno(const std::string& nome, const std::string& senha)
    : UsuarioAutenticavel(nome, senha) {}

bool Aluno::autenticar(const std::string& senha) const {
    return this->senha == senha;
}

std::string Aluno::gerarRelatorio() const {
    std::ostringstream oss;
    oss << "Relatório de Aluno - Nome: " << nome << "\nDisciplinas cursadas:\n";
    for (const auto& disciplina : historico) {
        oss << "- " << disciplina.getDetalhes() << "\n";
    }
    return oss.str();
}

void Aluno::adicionarDisciplina(const std::string& nomeDisciplina, int ano, float nota) {
    historico.emplace_back(nomeDisciplina, ano, nota);
}
