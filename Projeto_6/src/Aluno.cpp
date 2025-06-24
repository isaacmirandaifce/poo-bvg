#include "Aluno.h"
#include <iostream>

// implementação da classe interna
Aluno::HistoricoDisciplinar::HistoricoDisciplinar(const std::string& nome, int ano, double nota)
    : nomeDisciplina(nome), ano(ano), nota(nota) {}

void Aluno::HistoricoDisciplinar::exibir() const {
    std::cout << "Disciplina: " << nomeDisciplina 
              << ", Ano: " << ano 
              << ", Nota: " << nota << std::endl;
}

// métodos de Aluno
Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& senha)
    : UsuarioAutenticavel(nome, email, senha), tipo(TipoUsuario::ALUNO) {}

bool Aluno::autenticar(const std::string& tentativaSenha) const {
    return senha == tentativaSenha;
}

void Aluno::adicionarDisciplina(const std::string& nome, int ano, double nota) {
    historico.emplace_back(nome, ano, nota);
}

void Aluno::gerarRelatorio() const {
    std::cout << "Relatório do Aluno: " << nome << "\nEmail: " << email << "\nHistórico:\n";
    for (const auto& d : historico) {
        d.exibir();
    }
}

TipoUsuario Aluno::getTipo() const {
    return tipo;
}
