#include "../include/professor.h"
#include <iostream>

// Construtor padrão
Professor::Professor() : UsuarioAutenticavel("", "", TipoUsuario::PROFESSOR, ""), areaDeAtuacao("") {}

// Construtor parametrizado
Professor::Professor(const std::string nome, const std::string email, TipoUsuario tipo, std::string senha, const std::string areaDeAtuacao)
    : UsuarioAutenticavel(nome, email, TipoUsuario::PROFESSOR, senha), areaDeAtuacao(areaDeAtuacao) {}

// Método para adicionar uma disciplina ministrada
void Professor::adicionarDisciplina(const std::string& disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

// Sobrescrita de gerarRelatorio
void Professor::gerarRelatorio() const {
    std::cout << "Professor: " << nome << "\n"
              << "Area de Atuacao: " << areaDeAtuacao << "\n"
              << "Disciplinas Ministradas:\n";
    for (const auto& disciplina : disciplinasMinistradas) {
        std::cout << "  - " << disciplina << "\n";
    }
}


bool Professor::autenticar(const std::string& senha) const {
    return senha == getSenha(); // Usa o getter para acessar a senha armazenada
}