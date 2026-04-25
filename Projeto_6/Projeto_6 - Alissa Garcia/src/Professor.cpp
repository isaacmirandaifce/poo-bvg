#include "Professor.h"

Professor::Professor() : UsuarioAutenticavel() {
    areaDeAtuacao = "NULL";
}

Professor::Professor(string nome, string email, string senha, string area)
    : UsuarioAutenticavel(nome, email, TipoUsuario::PROFESSOR, senha) {
    areaDeAtuacao = area;
}

bool Professor::autenticar(string senha) {
    return this->senha == senha;
}

void Professor::disciplinasAdicionadas(string disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void Professor::gerarRelatorio() const {
    cout << "\n--- RELATÓRIO DO PROFESSOR ---\n";
    cout << "Nome: " << nome << endl;
    cout << "Área: " << areaDeAtuacao << endl;
    cout << "Disciplinas:\n";
    for (auto d : disciplinasMinistradas) {
        cout << "- " << d << endl;
    }
}
