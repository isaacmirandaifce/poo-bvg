#include "Aluno.h"
#include <iostream>

Aluno::Aluno(const std::string& nome, const std::string& senha)
    : nome(nome), senha(senha) {}

bool Aluno::autenticar(const std::string& senha) const {
    return this->senha == senha;
}

void Aluno::gerarRelatorio() const {
    std::cout << "Relatório do Aluno: " << nome << std::endl;
    mostrarHistorico();
}

TipoUsuario Aluno::getTipo() const {
    return TipoUsuario::ALUNO;
}

void Aluno::adicionarDisciplina(const std::string& disciplina, int ano, float nota) {
    historico.push_back(HistoricoDisciplinar(disciplina, ano, nota));
}

void Aluno::mostrarHistorico() const {
    for (const auto& disc : historico) {
        std::cout << "Disciplina: " << disc.getDisciplina() 
                  << ", Ano: " << disc.getAno() 
                  << ", Nota: " << disc.getNota() << std::endl;
    }
}

Aluno::HistoricoDisciplinar::HistoricoDisciplinar(const std::string& disciplina, int ano, float nota)
    : disciplina(disciplina), ano(ano), nota(nota) {}

std::string Aluno::HistoricoDisciplinar::getDisciplina() const {
    return disciplina;
}

int Aluno::HistoricoDisciplinar::getAno() const {
    return ano;
}

float Aluno::HistoricoDisciplinar::getNota() const {
    return nota;
}