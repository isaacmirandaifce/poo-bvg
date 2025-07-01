#include "Professor.h"
#include <iostream>

Professor::Professor(int id, std::string nome, std::string senha, std::string departamento)
    : UsuarioAutenticavel(id, nome, TipoUsuario::PROFESSOR, senha), departamento(departamento) {}

void Professor::adicionarDisciplina(const std::string& disciplina) {
    disciplinasLecionadas.push_back(disciplina);
}

bool Professor::autenticar(const std::string& senha) const {
    std::cout << "Autenticando professor '" << this->nome << "'... ";
    return verificarSenha(senha);
}

void Professor::gerarRelatorio() const {
    std::cout << "\n--- Relatorio do Professor ---" << std::endl;
    std::cout << "ID: " << this->id << std::endl;
    std::cout << "Nome: " << this->nome << std::endl;
    std::cout << "Tipo: " << this->getTipoAsString() << std::endl;
    std::cout << "Departamento: " << this->departamento << std::endl;
    std::cout << "Disciplinas Lecionadas:" << std::endl;
    if (disciplinasLecionadas.empty()) {
        std::cout << "  Nenhuma disciplina registrada." << std::endl;
    } else {
        for (const auto& disciplina : disciplinasLecionadas) {
            std::cout << "  - " << disciplina << std::endl;
        }
    }
    std::cout << "----------------------------" << std::endl;
}