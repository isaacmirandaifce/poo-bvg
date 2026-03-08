#include "Professor.h"
#include <algorithm>

Professor::Professor(std::string nome, std::string email, std::string senha, std::string departamento)
    : UsuarioAutenticavel(nome, email, TipoUsuario::PROFESSOR, senha),
      departamento(departamento) {}

bool Professor::autenticar(std::string senha) const {
    return this->senha == senha;
}

void Professor::adicionarDisciplinaMinistrada(const std::string& disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

bool Professor::ministra(const std::string& disciplina) const {
    return std::find(disciplinasMinistradas.begin(), disciplinasMinistradas.end(), disciplina)
           != disciplinasMinistradas.end();
}

void Professor::gerarRelatorio() const {
    std::cout << "Relatorio do Professor\n";
    std::cout << "Nome: " << nome << "\nEmail: " << email << "\n";
    std::cout << "Departamento: " << departamento << "\n";

    if (!disciplinasMinistradas.empty()) {
        std::cout << "Disciplinas ministradas:\n";
        for (const auto& d : disciplinasMinistradas) {
            std::cout << " - " << d << "\n";
        }
    }
}
