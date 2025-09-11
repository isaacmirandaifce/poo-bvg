#include "Aluno.h"
#include <iostream>

// implementacao da classe interna
Aluno::HistoricoDisciplinar::HistoricoDisciplinar(const std::string& nome, int ano, double nota)
    : nomeDisciplina(nome), ano(ano), nota(nota) {}

void Aluno::HistoricoDisciplinar::exibir() const {
    std::cout << "Disciplina: " << nomeDisciplina 
              << ", Ano: " << ano 
              << ", Nota: " << nota << std::endl;
}

// metodos de Aluno
Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& senha)
    : UsuarioAutenticavel(nome, email, senha), tipo(TipoUsuario::ALUNO) {}

bool Aluno::autenticar(const std::string& tentativaSenha) const {
    return senha == tentativaSenha;
}

void Aluno::adicionarDisciplina(const std::string& nome, int ano, double nota) {
    historico.emplace_back(nome, ano, nota);
}

void Aluno::gerarRelatorio() const {
    std::cout << "Relatorio do Aluno: " << nome << "\nEmail: " << email << "\nHistorico:\n";
    for (const auto& d : historico) {
        d.exibir();
    }
}

TipoUsuario Aluno::getTipo() const {
    return tipo;
}

double Aluno::calcularMediaGeral() const {
    if (historico.empty()) return 0.0;
    double soma = 0.0;
    for (const auto& d : historico) {
        soma += d.getNota();
    }
    return soma / historico.size();
}
