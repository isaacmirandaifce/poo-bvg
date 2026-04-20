#include "Professor.h"
#include <iostream>

Professor::Professor() : UsuarioAutenticavel(), areaDeAtuacao(""), senhaHash(0) {
    tipo = TipoUsuario::PROFESSOR;
}

Professor::Professor(const std::string& nome, const std::string& email,
                     const std::string& areaDeAtuacao, const std::vector<std::string>& disciplinas)
    : UsuarioAutenticavel(nome, email, TipoUsuario::PROFESSOR), areaDeAtuacao(areaDeAtuacao), disciplinasMinistradas(disciplinas), senhaHash(0) {}

void Professor::setSenha(const std::string& senha) {
    senhaHash = UsuarioAutenticavel::hashSenha(senha);
}

bool Professor::autenticar(const std::string& senha) const {
    return senhaHash != 0 && senhaHash == UsuarioAutenticavel::hashSenha(senha);
}

void Professor::gerarRelatorio() const {
    std::cout << "[Professor] Nome: " << nome << " | Área: " << areaDeAtuacao << std::endl;
    if (!disciplinasMinistradas.empty()) {
        std::cout << "Disciplinas ministradas:" << std::endl;
        for (const auto& d : disciplinasMinistradas) {
            std::cout << "- " << d << std::endl;
        }
    }
}

void Professor::adicionarDisciplinaMinistrada(const std::string& d) {
    disciplinasMinistradas.push_back(d);
}
