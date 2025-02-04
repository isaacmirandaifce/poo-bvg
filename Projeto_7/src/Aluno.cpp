#include "Aluno.h"

Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& matricula, 
             const std::string& curso, const std::string& senha)
    : UsuarioAutenticavel(nome, email, "Aluno", senha), matricula(matricula), curso(curso) {}

void Aluno::adicionarDisciplina(const std::string& disciplina) {
    disciplinasCursadas.push_back(disciplina);
}

void Aluno::adicionarHistorico(const std::string& disciplina, int ano, double nota) {
    historico.push_back({disciplina, ano, nota});
}

double Aluno::calcularMedia() const {
    double soma = 0.0;
    int total = 0;
    for (const auto& h : historico) {
        soma += h.nota;
        total++;
    }
    return (total > 0) ? soma / total : 0.0;
}

std::vector<std::string> Aluno::getDisciplinasPorAno(int ano) const {
    std::vector<std::string> disciplinas;
    for (const auto& h : historico) {
        if (h.ano == ano) {
            disciplinas.push_back(h.disciplina);
        }
    }
    return disciplinas;
}

void Aluno::gerarRelatorio() const {
    std::cout << "Relatório do Aluno:" << std::endl;
    std::cout << "Nome: " << nome << "\nEmail: " << email << std::endl;
    std::cout << "Matrícula: " << matricula << "\nCurso: " << curso << std::endl;
    std::cout << "Disciplinas Cursadas:" << std::endl;
    for (const auto& disciplina : disciplinasCursadas) {
        std::cout << "- " << disciplina << std::endl;
    }
    std::cout << "Histórico Disciplinar:" << std::endl;
    for (const auto& h : historico) {
        std::cout << "- " << h.disciplina << ", Ano: " << h.ano << ", Nota: " << h.nota << std::endl;
    }
}

bool Aluno::autenticar(const std::string& senhaTentativa) const {
    return senha == senhaTentativa;
}
