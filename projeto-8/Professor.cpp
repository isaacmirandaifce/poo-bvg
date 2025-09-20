#include "Professor.h"
#include <iostream>

Professor::Professor(std::string nome, std::string email, std::string senha, std::string areaDeAtuacao)
    : UsuarioAutenticavel(nome, email, TipoUsuario::PROFESSOR, senha), areaDeAtuacao(areaDeAtuacao) {
}

void Professor::adicionarDisciplina(const std::string& disciplina) {
    this->disciplinasMinistradas.push_back(disciplina);
}

bool Professor::autenticar(const std::string& senha) {
    return this->getSenha() == senha;
}

void Professor::gerarRelatorio() {
    std::cout << "--- Relatorio do Professor ---\n"
              << "Nome: " << this->nome << "\n"
              << "Area de Atuacao: " << this->areaDeAtuacao << "\n"
              << "------------------------------------\n"
              << "Disciplinas Ministradas:\n";

    if (disciplinasMinistradas.empty()) {
        std::cout << "Nenhuma disciplina ministrada.\n";
    } else {
        for (const auto& disciplina : disciplinasMinistradas) {
            std::cout << "  - " << disciplina << "\n";
        }
    }
}
