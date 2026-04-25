#include "Aluno.h"
#include <iostream>
#include <iomanip>

Aluno::Aluno() : UsuarioAutenticavel(), matricula(""), curso(""), senhaHash(0) {
    tipo = TipoUsuario::ALUNO;
}

Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& matricula,
             const std::string& curso)
    : UsuarioAutenticavel(nome, email, TipoUsuario::ALUNO), matricula(matricula), curso(curso), senhaHash(0) {}

void Aluno::setSenha(const std::string& senha) {
    senhaHash = UsuarioAutenticavel::hashSenha(senha);
}

bool Aluno::autenticar(const std::string& senha) const {
    return senhaHash != 0 && senhaHash == UsuarioAutenticavel::hashSenha(senha);
}

void Aluno::gerarRelatorio() const {
    std::cout << "[Aluno] Nome: " << nome << " | Matrícula: " << matricula
              << " | Curso: " << curso << std::endl;
    if (!historico.empty()) {
        std::cout << "Histórico disciplinar:" << std::endl;
        for (const auto& h : historico) {
            std::cout << "- " << h.getNome() << " (" << h.getAno() << ") - Nota: "
                      << std::fixed << std::setprecision(1) << h.getNota() << std::endl;
        }
    }
    exibirDisciplinas();
}

void Aluno::adicionarDisciplina(const Disciplina& d) {
    disciplinas.push_back(d);
}

void Aluno::adicionarHistorico(const std::string& nome, int ano, float nota) {
    historico.emplace_back(nome, ano, nota);
}

void Aluno::exibirDisciplinas() const {
    if (disciplinas.empty()) {
        std::cout << "Nenhuma disciplina associada." << std::endl;
        return;
    }

    std::cout << "Disciplinas e situação:" << std::endl;
    for (const auto& d : disciplinas) {
        std::cout << "- " << d.getNome() << " (CH: " << d.getCargaHoraria() << ") - Nota: "
                  << std::fixed << std::setprecision(1) << d.getNota()
                  << " -> " << (verificarAprovacao(d) ? "Aprovado" : "Reprovado") << std::endl;
    }
}

const std::string& Aluno::getMatricula() const { return matricula; }
const std::string& Aluno::getCurso() const { return curso; }
