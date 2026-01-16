#include "Aluno.h"
#include <iostream>
#include <iomanip>

Aluno::Historico::Historico(const std::string& d, int a, float n)
    : disciplina(d), ano(a), nota(n) {}

std::string Aluno::Historico::getDisciplina() const { return disciplina; }
int Aluno::Historico::getAno() const { return ano; }
float Aluno::Historico::getNota() const { return nota; }

Aluno::Aluno() : UsuarioAutenticavel(), senhaHash(0) {
    tipo = TipoUsuario::ALUNO;
}

Aluno::Aluno(const std::string& nome, const std::string& email,
             const std::string& matricula, const std::string& curso)
    : UsuarioAutenticavel(nome, email, TipoUsuario::ALUNO),
      matricula(matricula), curso(curso), senhaHash(0) {}

void Aluno::definirSenha(const std::string& senha) {
    senhaHash = gerarHash(senha);
}

bool Aluno::autenticar(const std::string& senha) const {
    return senhaHash == gerarHash(senha);
}

void Aluno::adicionarDisciplina(const Disciplina& d) {
    disciplinas.push_back(d);
}

void Aluno::adicionarHistorico(const std::string& nome, int ano, float nota) {
    historico.emplace_back(nome, ano, nota);
}

const std::vector<Aluno::Historico>& Aluno::getHistorico() const {
    return historico;
}

const std::vector<Disciplina>& Aluno::getDisciplinas() const {
    return disciplinas;
}

void Aluno::gerarRelatorio() const {
    std::cout << "Aluno: " << nome << " | Curso: " << curso << "\n";
    for (const auto& h : historico) {
        std::cout << "- " << h.getDisciplina()
                  << " (" << h.getAno() << ") Nota: "
                  << std::fixed << std::setprecision(1)
                  << h.getNota() << "\n";
    }
}
