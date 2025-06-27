#include "Persistencia.h"
#include <iostream>
#include <sstream>

std::vector<std::shared_ptr<Aluno>> Persistencia::carregarAlunos(const std::string& caminho) {
    std::vector<std::shared_ptr<Aluno>> alunos;
    std::ifstream arquivo(caminho);
    if (!arquivo) {
        throw ArquivoNaoEncontradoException();
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::istringstream ss(linha);
        std::string nome, email, senha;
        if (std::getline(ss, nome, ',') && std::getline(ss, email, ',') && std::getline(ss, senha)) {
            alunos.push_back(std::make_shared<Aluno>(nome, email, senha));
        } else {
            throw ErroConversaoDadosException();
        }
    }
    return alunos;
}

void Persistencia::salvarAlunos(const std::vector<std::shared_ptr<Aluno>>& alunos, const std::string& caminho) {
    std::ofstream arquivo(caminho);
    if (!arquivo) {
        throw PermissaoNegadaException();
    }

    for (const auto& aluno : alunos) {
        arquivo << aluno->getNome() << "," << aluno->getEmail() << "," << aluno->getSenha() << "\n";
    }
}

std::vector<std::shared_ptr<Professor>> Persistencia::carregarProfessores(const std::string& caminho) {
    std::vector<std::shared_ptr<Professor>> professores;
    std::ifstream arquivo(caminho);
    if (!arquivo) {
        throw ArquivoNaoEncontradoException();
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::istringstream ss(linha);
        std::string nome, email, senha, disciplina;
        if (std::getline(ss, nome, ',') && std::getline(ss, email, ',') &&
            std::getline(ss, senha, ',') && std::getline(ss, disciplina)) {
            professores.push_back(std::make_shared<Professor>(nome, email, senha, disciplina));
        } else {
            throw ErroConversaoDadosException();
        }
    }
    return professores;
}

void Persistencia::salvarProfessores(const std::vector<std::shared_ptr<Professor>>& professores, const std::string& caminho) {
    std::ofstream arquivo(caminho);
    if (!arquivo) {
        throw PermissaoNegadaException();
    }

    for (const auto& prof : professores) {
        arquivo << prof->getNome() << "," << prof->getEmail() << "," << prof->getSenha() << "," << prof->getDisciplina() << "\n";
    }
}
