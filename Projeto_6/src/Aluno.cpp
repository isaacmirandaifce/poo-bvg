#include "Aluno.h"
#include <iostream>

void Aluno::HistoricoDisciplinar::adicionarDisciplina(const std::string& nome, int ano, float nota) {
    disciplinas.push_back({nome, ano, nota});
}

std::string Aluno::HistoricoDisciplinar::getHistoricoFormatado() const {
    if (disciplinas.empty()) {
        return "Nenhuma disciplina cursada.\n";
    }

    std::stringstream ss;
    ss << "--- Historico de Disciplinas ---\n";
    for (const auto& d : disciplinas) {
        ss << "Disciplina: " << d.nomeDisciplina
           << ", Ano: " << d.anoCursado
           << ", Nota: " << d.nota << "\n";
    }
    return ss.str();
}

Aluno::Aluno(std::string nome, std::string cpf, std::string senha, std::string matricula)
    : UsuarioAutenticavel(nome, cpf, TipoUsuario::ALUNO, senha), matricula(matricula) {}

bool Aluno::autenticar(const std::string& senhaFornecida) const {

    return this->senha == senhaFornecida;
}

std::string Aluno::gerarRelatorio() const {
    std::stringstream ss;
    ss << "===== Relatorio do Aluno =====\n";
    ss << "Nome: " << nome << "\n";
    ss << "CPF: " << cpf << "\n";
    ss << "Matricula: " << matricula << "\n";
    ss << historico.getHistoricoFormatado();
    ss << "==============================\n";
    return ss.str();
}

Aluno::HistoricoDisciplinar& Aluno::getHistorico() {
    return historico;
}