#include "Professor.h"
#include <iostream>
#include <algorithm>

Professor::Professor(const std::string& nome, const std::string& email, int id,
                     const std::string& senha, const std::string& departamento,
                     const std::string& titulacao)
    : UsuarioAutenticavel(nome, email, id, TipoUsuario::PROFESSOR, senha),
      departamento(departamento), titulacao(titulacao) {}

std::string Professor::getDepartamento() const { return departamento; }
std::string Professor::getTitulacao() const { return titulacao; }
void Professor::setDepartamento(const std::string& departamento) { this->departamento = departamento; }
void Professor::setTitulacao(const std::string& titulacao) { this->titulacao = titulacao; }

void Professor::adicionarDisciplina(const std::string& disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}

void Professor::removerDisciplina(const std::string& disciplina) {
    auto it = std::find(disciplinasMinistradas.begin(), disciplinasMinistradas.end(), disciplina);
    if (it != disciplinasMinistradas.end()) {
        disciplinasMinistradas.erase(it);
    }
}

bool Professor::autenticar(const std::string& senha) {
    return gerarHash(senha) == senhaHash;
}

void Professor::gerarRelatorio() const {
    std::cout << "\n=== RELATÓRIO DO PROFESSOR ===" << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Departamento: " << departamento << std::endl;
    std::cout << "Titulação: " << titulacao << std::endl;

    if (!disciplinasMinistradas.empty()) {
        std::cout << "\nDisciplinas Ministradas:" << std::endl;
        for (size_t i = 0; i < disciplinasMinistradas.size(); ++i) {
            std::cout << "  " << (i + 1) << ". " << disciplinasMinistradas[i] << std::endl;
        }
    }
    std::cout << "==============================" << std::endl;
}

void Professor::exibirInformacoes() const {
    Usuario::exibirInformacoes();
    std::cout << "Departamento: " << departamento << "\nTitulação: " << titulacao << std::endl;
}
