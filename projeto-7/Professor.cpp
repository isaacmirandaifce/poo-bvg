#include "Professor.h"
#include <iostream>

// Implementação do construtor de Professor
Professor::Professor(std::string nome, std::string email, std::string senha, std::string areaDeAtuacao)
    // Chama o construtor da classe mãe (UsuarioAutenticavel)
    : UsuarioAutenticavel(nome, email, TipoUsuario::PROFESSOR, senha), areaDeAtuacao(areaDeAtuacao) {
}

// Método para adicionar disciplinas que o professor ministra
void Professor::adicionarDisciplina(const std::string& disciplina) {
    this->disciplinasMinistradas.push_back(disciplina);
}

// Implementação do método de autenticação
bool Professor::autenticar(const std::string& senha) {
    // A lógica é a mesma do Aluno: compara a senha fornecida com a armazenada
    return this->getSenha() == senha;
}

// Implementação do método de relatório
void Professor::gerarRelatorio() {
    std::cout << "--- Relatorio do Professor ---" << std::endl;
    std::cout << "Nome: " << this->nome << std::endl;
    std::cout << "Area de Atuacao: " << this->areaDeAtuacao << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Disciplinas Ministradas:" << std::endl;

    if (disciplinasMinistradas.empty()) {
        std::cout << "Nenhuma disciplina ministrada." << std::endl;
    } else {
        for (const auto& disciplina : disciplinasMinistradas) {
            std::cout << "  - " << disciplina << std::endl;
        }
    }
}

bool Professor::ministraDisciplina(const std::string& nomeDisciplina) const {
    for (const std::string& disciplina : this->disciplinasMinistradas) {
        if (disciplina == nomeDisciplina) {
            return true;
        }
    }
    return false;
}
