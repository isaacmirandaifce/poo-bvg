#include "Aluno.h"

Aluno::Aluno(const std::string& nome,
             const std::string& email,
             const std::string& senha)
    : UsuarioAutenticavel(nome, email, TipoUsuario::ALUNO, senha) {}

bool Aluno::autenticar(const std::string& senhaInformada) const {
    return senha == senhaInformada;
}

Aluno::HistoricoDisciplinar::HistoricoDisciplinar(
    const std::string& disciplina, int ano, float nota)
    : disciplina(disciplina), ano(ano), nota(nota) {}

void Aluno::HistoricoDisciplinar::exibir() const {
    std::cout << disciplina << " (" << ano << ") - Nota: " << nota << std::endl;
}

void Aluno::adicionarHistorico(const std::string& disciplina, int ano, float nota) {
    historico.emplace_back(disciplina, ano, nota);
}

void Aluno::gerarRelatorio() const {
    std::cout << "Relatório do Aluno: " << nome << std::endl;
    for (const auto& h : historico) {
        h.exibir();
    }
}