#include "Aluno.h"
#include <iostream>

// Construtor
Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& matricula, 
             const std::string& curso, const std::string& senha)
    : UsuarioAutenticavel(nome, email, "Aluno", senha), matricula(matricula), curso(curso) {}

// Adicionar disciplina cursada
void Aluno::adicionarDisciplina(const std::string& disciplina) {
    disciplinasCursadas.push_back(disciplina);
}

// Adicionar histórico disciplinar com nome da disciplina, ano e nota
void Aluno::adicionarHistorico(const std::string& nomeDisciplina, int ano, double nota) {
    historico.emplace_back(nomeDisciplina, ano, nota);
}

// Gerar relatório básico
void Aluno::gerarRelatorio() const {
    std::cout << "Relatório do Aluno:\n";
    std::cout << "Nome: " << nome << "\nEmail: " << email << "\n";
    std::cout << "Matrícula: " << matricula << "\nCurso: " << curso << "\n";
    std::cout << "Disciplinas Cursadas:\n";
    for (const auto& disciplina : disciplinasCursadas) {
        std::cout << "- " << disciplina << "\n";
    }
}

// Gerar relatório detalhado (com histórico disciplinar)
void Aluno::gerarRelatorio(bool incluirNotas) const {
    std::cout << "Relatório do Aluno:\n";
    std::cout << "Nome: " << nome << "\nEmail: " << email << "\n";
    std::cout << "Matrícula: " << matricula << "\nCurso: " << curso << "\n";

    if (incluirNotas) {
        std::cout << "Histórico Disciplinar:\n";
        for (const auto& h : historico) {
            std::cout << "- Disciplina: " << h.nomeDisciplina
                      << ", Ano: " << h.anoCursado
                      << ", Nota: " << h.nota << "\n";
        }
    }
}

// Método para autenticar o aluno
bool Aluno::autenticar(const std::string& senhaTentativa) const {
    return senha == senhaTentativa;
}


