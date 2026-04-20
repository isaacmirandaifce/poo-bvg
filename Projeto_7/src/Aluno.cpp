#include <iostream>
#include "../include/Aluno.h"

// Classe interna
Aluno::HistoricoDisciplinar::HistoricoDisciplinar(
    std::string disciplina,
    int ano,
    float nota
) : disciplina(disciplina), ano(ano), nota(nota) {}

//Aluno
Aluno::Aluno(std::string nome, std::string senha)
    : UsuarioAutenticavel(nome, TipoUsuario::ALUNO, senha) {}

bool Aluno::autenticar(std::string senha) const {
    return this->senha == senha;
}

void Aluno::adicionarDisciplina(std::string disciplina, int ano, float nota) {
    historico.emplace_back(disciplina, ano, nota);
}

void Aluno::gerarRelatorio() const {
    std::cout << "\n=== Relatório do Aluno ===\n";
    std::cout << "Nome: " << nome << "\n";
    std::cout << "Histórico:\n";

    for (const auto& h: historico) {
        std::cout << "- " << h.disciplina
                  << " (" << h.ano << ")"
                  << " Nota: " << h.nota << "\n";
    }
}

    //Getter do histórico
    const std::vector<Aluno::HistoricoDisciplinar>& Aluno::getHistorico() const {
    return historico;
    };