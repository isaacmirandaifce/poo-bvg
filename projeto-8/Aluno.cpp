#include "Aluno.h"
#include <iostream>
#include <numeric>

Aluno::Aluno(std::string nome, std::string email, std::string senha, std::string matricula, std::string curso)
    : UsuarioAutenticavel(nome, email, TipoUsuario::ALUNO, senha), matricula(matricula), curso(curso) {
}

void Aluno::adicionarDisciplinaAoHistorico(const std::string& disciplina, int ano, double nota) {
    historico.emplace_back(disciplina, ano, nota);
}

const std::string& Aluno::getMatricula() const { return this->matricula; }
const std::string& Aluno::getCurso() const { return this->curso; }
const std::vector<Aluno::HistoricoDisciplinar>& Aluno::getHistorico() const { return this->historico; }

double Aluno::getMediaGeral() const {
    if (historico.empty()) return 0.0;
    double somaDasNotas = 0.0;
    for (const auto& disciplina : historico) {
        somaDasNotas += disciplina.nota;
    }
    return somaDasNotas / historico.size();
}

bool Aluno::autenticar(const std::string& senha) {
    return this->getSenha() == senha;
}

void Aluno::gerarRelatorio() {
    std::cout << "--- Relatorio Academico do Aluno ---\n"
              << "Nome: " << this->nome << "\n"
              << "Matricula: " << this->matricula << "\n"
              << "Curso: " << this->curso << "\n"
              << "------------------------------------\n"
              << "Historico Disciplinar:\n";

    if (historico.empty()) {
        std::cout << "Nenhuma disciplina cursada.\n";
    } else {
        for (const auto& disciplina : historico) {
            std::cout << "  - Disciplina: " << disciplina.nomeDisciplina
                      << ", Ano: " << disciplina.anoCursado
                      << ", Nota: " << disciplina.nota << "\n";
        }
    }
}
