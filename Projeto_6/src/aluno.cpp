#include "aluno.h"
#include <iostream>

// Construtor da classe Aluno
Aluno::Aluno(const std::string& nome, const std::string& email, TipoUsuario tipo, const std::string& senha, const std::string& curso)
    : UsuarioAutenticavel(nome, email, tipo, senha), curso(curso) {}

// Método para adicionar disciplina
void Aluno::adicionarDisciplina(const std::shared_ptr<Disciplina>& disciplina) {
    disciplinas.push_back(disciplina);
}

// Sobrescrita do método para gerar o relatório do aluno
void Aluno::gerarRelatorio() const {
    std::cout << "Relatorio do Aluno\n"
              << "Nome: " << nome << "\n"
              << "Email: " << email << "\n"
              << "Curso: " << curso << "\nDisciplinas:\n";

    for (const auto& disciplina : disciplinas) {
        disciplina->exibirInformacoes();
        std::cout << "---------------------\n";
    }

    std::cout << "\nHistorico Disciplinar:\n";
    for (const auto& historico : historicoDisciplinar) {
        historico.exibirInformacoes();
        std::cout << "---------------------\n";
    }
}

// Getter para disciplinas
const std::vector<std::shared_ptr<Disciplina>>& Aluno::getDisciplinas() const {
    return disciplinas;
}

bool Aluno::autenticar(const std::string& senha) const {
    return senha == getSenha(); // Usa o getter para acessar a senha armazenada
}

// Método para adicionar ao histórico
void Aluno::adicionarAoHistorico(const std::string& nomeDisciplina, int ano, float nota) {
    HistoricoDisciplinar historico(nomeDisciplina, ano, nota);
    historicoDisciplinar.push_back(historico);
}
