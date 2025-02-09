#include "../include/Professor.h"
#include <iostream>

Professor::Professor() : UsuarioAutenticavel(), areaDeAtuacao("") {}

Professor::Professor(const std::string& nome, const std::string& email, const std::string& areaDeAtuacao)
    : UsuarioAutenticavel(nome, email, "Professor", ""), areaDeAtuacao(areaDeAtuacao) {}

Professor::Professor(const std::string& nome, const std::string& email, const std::string& areaDeAtuacao, const std::string& senha)
    : UsuarioAutenticavel(nome, email, "Professor", senha), areaDeAtuacao(areaDeAtuacao) {}

bool Professor::autenticar(const std::string& senha) const {
    return verificarSenha(senha);
}

void Professor::gerarRelatorio() const {
    std::cout << "Relatorio do Professor:\n"
              << "Nome: " << nome << "\n"
              << "Area de Atuacao: " << areaDeAtuacao << "\n"
              << "Disciplinas Ministradas:\n";
    for (const auto& disciplina : disciplinasMinistradas) {
        std::cout << " - " << disciplina << "\n";
    }
}

void Professor::adicionarDisciplina(const std::string& disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

const std::vector<std::string>& Professor::getDisciplinasMinistradas() const {
    return disciplinasMinistradas;
}

bool Professor::ministraDisciplina(const std::string& disciplina) const {
    for (const auto& d : disciplinasMinistradas) {
        if (d == disciplina) {
            return true;
        }
    }
    return false;
}

std::string Professor::getNome() const {
    return nome;
}