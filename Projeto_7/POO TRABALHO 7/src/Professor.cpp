#include "Professor.h"
#include <iostream>

Professor::Professor()
    : UsuarioAutenticavel(), areaAtuacao(""), senhaHash(0) {
    tipo = TipoUsuario::PROFESSOR;
}

Professor::Professor(const std::string& nome,
                     const std::string& email,
                     const std::string& areaAtuacao,
                     const std::vector<std::string>& disciplinas)
    : UsuarioAutenticavel(nome, email, TipoUsuario::PROFESSOR),
      areaAtuacao(areaAtuacao),
      disciplinasMinistradas(disciplinas),
      senhaHash(0) {}

void Professor::definirSenha(const std::string& senha) {
    senhaHash = gerarHash(senha);
}

bool Professor::autenticar(const std::string& senha) const {
    return senhaHash == gerarHash(senha);
}

void Professor::adicionarDisciplina(const std::string& disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

const std::vector<std::string>& Professor::getDisciplinasMinistradas() const {
    return disciplinasMinistradas;
}

void Professor::gerarRelatorio() const {
    std::cout << "Professor: " << nome
              << " | Área de atuação: " << areaAtuacao << std::endl;

    if (!disciplinasMinistradas.empty()) {
        std::cout << "Disciplinas ministradas:" << std::endl;
        for (const auto& d : disciplinasMinistradas) {
            std::cout << "- " << d << std::endl;
        }
    }
}
