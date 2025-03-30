#include "Aluno.h"
#include <iostream>

Aluno::HistoricoDisciplinar::HistoricoDisciplinar(std::string disciplina, int ano, float nota)
    : disciplina(disciplina), ano(ano), nota(nota) {}

void Aluno::HistoricoDisciplinar::exibirHistorico() const {
    std::cout << "Disciplina: " << disciplina << ", Ano: " << ano << ", Nota: " << nota << "\n";
}

Aluno::Aluno(std::string nome, std::string matricula, std::string curso, std::string senha, double media)
    : UsuarioAutenticavel(senha), nome(nome), matricula(matricula), curso(curso), media(media) {}

bool Aluno::autenticar(std::string senha) const {
    return this->senha == senha;
}

void Aluno::gerarRelatorio() const {
    std::cout << "Relatorio do Aluno:\n";
    std::cout << "Nome: " << nome << "\nMatricula: " << matricula << "\nCurso: " << curso << "\n";
}

void Aluno::adicionarDisciplinaAoHistorico(std::string disciplina, int ano, float nota) {
    historico.push_back(HistoricoDisciplinar(disciplina, ano, nota));
}

void Aluno::exibirHistoricoCompleto() const {
    std::cout << "Historico Disciplinar:\n";
    for (const auto& h : historico) {
        h.exibirHistorico();
    }
}

double Aluno::getMedia() const {
    return media;
}

void Aluno::exibirInformacoes() const {
    std::cout << "Nome: " << nome << ", Matricula: " << matricula << ", Curso: " << curso << ", Media: " << media << "\n";
}