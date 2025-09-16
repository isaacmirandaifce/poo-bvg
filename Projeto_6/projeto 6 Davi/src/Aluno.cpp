
#include "../include/Aluno.h"
#include <iostream>

Aluno::Aluno(std::string nome, std::string login, std::string senha)
    : UsuarioAutenticavel(nome, login, senha) {}

bool Aluno::autenticar(std::string senhaTentativa) {
    return senha == senhaTentativa;
}

void Aluno::adicionarDisciplina(std::string nome, int ano, float nota) {
    historico.emplace_back(nome, ano, nota);
}

void Aluno::gerarRelatorio() const {
    std::cout << "Relatório do Aluno: " << nome << std::endl;
    for (const auto& disciplina : historico) {
        disciplina.exibir();
    }
}

Aluno::HistoricoDisciplinar::HistoricoDisciplinar(std::string nome, int ano, float nota)
    : nomeDisciplina(nome), ano(ano), nota(nota) {}

void Aluno::HistoricoDisciplinar::exibir() const {
    std::cout << "Disciplina: " << nomeDisciplina
              << ", Ano: " << ano
              << ", Nota: " << nota << std::endl;
}
