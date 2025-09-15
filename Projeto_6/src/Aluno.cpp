#include "Aluno.h"
#include <iostream>
#include <iomanip>

// Implementação da classe interna HistoricoDisciplinar
Aluno::HistoricoDisciplinar::HistoricoDisciplinar(const std::string& disciplina, int ano, double nota)
    : nomeDisciplina(disciplina), anoCursado(ano), nota(nota) {}

std::string Aluno::HistoricoDisciplinar::getNomeDisciplina() const { return nomeDisciplina; }
int Aluno::HistoricoDisciplinar::getAnoCursado() const { return anoCursado; }
double Aluno::HistoricoDisciplinar::getNota() const { return nota; }

void Aluno::HistoricoDisciplinar::exibirHistorico() const {
    std::cout << "  " << nomeDisciplina << " (" << anoCursado << ") - Nota: "
              << std::fixed << std::setprecision(1) << nota << std::endl;
}

// Implementação da classe Aluno
Aluno::Aluno(const std::string& nome, const std::string& email, int id,
             const std::string& senha, const std::string& curso, int periodo)
    : UsuarioAutenticavel(nome, email, id, TipoUsuario::ALUNO, senha),
      curso(curso), periodo(periodo) {}

void Aluno::setCurso(const std::string& curso) { this->curso = curso; }
void Aluno::setPeriodo(int periodo) { this->periodo = periodo; }
std::string Aluno::getCurso() const { return curso; }
int Aluno::getPeriodo() const { return periodo; }

void Aluno::adicionarDisciplina(const std::string& disciplina, int ano, double nota) {
    historico.emplace_back(disciplina, ano, nota);
}

bool Aluno::autenticar(const std::string& senha) {
    return gerarHash(senha) == senhaHash;
}

void Aluno::gerarRelatorio() const {
    std::cout << "\n=== RELATÓRIO DO ALUNO ===" << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Curso: " << curso << std::endl;
    std::cout << "Período: " << periodo << "º" << std::endl;

    if (!historico.empty()) {
        std::cout << "\nHistórico Acadêmico:" << std::endl;
        double somaNotas = 0;
        for (const auto& disciplina : historico) {
            disciplina.exibirHistorico();
            somaNotas += disciplina.getNota();
        }

        double media = somaNotas / historico.size();
        std::cout << "Média Geral: " << std::fixed << std::setprecision(2) << media << std::endl;
    }
    std::cout << "=========================" << std::endl;
}

void Aluno::exibirInformacoes() const {
    Usuario::exibirInformacoes();
    std::cout << "Curso: " << curso << "\nPeríodo: " << periodo << "º" << std::endl;
}

void Aluno::exibirHistoricoCompleto() const {
    if (historico.empty()) {
        std::cout << "Nenhuma disciplina cursada ainda." << std::endl;
        return;
    }

    std::cout << "\n--- Histórico Acadêmico Completo ---" << std::endl;
    for (const auto& disciplina : historico) {
        disciplina.exibirHistorico();
    }
}
