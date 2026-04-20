#include "Aluno.h"
#include <iostream>

Aluno::HistoricoDisciplinar::HistoricoDisciplinar(
    std::string disciplina, int ano, float nota)
    : disciplina(disciplina), ano(ano), nota(nota) {}

void Aluno::HistoricoDisciplinar::exibir() const {
    std::cout << disciplina << " (" << ano << ") - Nota: " << nota << std::endl;
}

Aluno::Aluno(std::string nome, std::string matricula, std::string senha)
    : UsuarioAutenticavel(nome, matricula, TipoUsuario::ALUNO, senha) {}

bool Aluno::autenticar(const std::string& senha) const {
    return this->senha == senha;
}

void Aluno::adicionarDisciplina(std::string disciplina, int ano, float nota) {
    historico.emplace_back(disciplina, ano, nota);
}

void Aluno::gerarRelatorio() const {
    std::cout << "\nRelatório do Aluno: " << nome << std::endl;
    for (const auto& h : historico) {
        h.exibir();
    }
}
