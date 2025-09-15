#include "Aluno.h"
#include <iostream>

Aluno::HistoricoDisciplinar::HistoricoDisciplinar(std::string disciplina, int ano, float nota)
    : disciplina(disciplina), ano(ano), nota(nota) {}

Aluno::Aluno(std::string nome, std::string email, std::string senha)
    : UsuarioAutenticavel(nome, email, TipoUsuario::ALUNO, senha) {}

bool Aluno::autenticar(std::string senhaDigitada) const {
    return senhaDigitada == senha;
}

void Aluno::adicionarDisciplina(std::string disciplina, int ano, float nota) {
    historico.emplace_back(disciplina, ano, nota);
}

void Aluno::gerarRelatorio() const {
    std::cout << "Relatorio do Aluno: " << nome << "\n";
    if (historico.empty()) {
        std::cout << "(Nenhuma disciplina registrada)\n";
    }
    for (const auto& h : historico) {
        std::cout << "- " << h.disciplina << " (" << h.ano << ") Nota: " << h.nota << "\n";
    }
}