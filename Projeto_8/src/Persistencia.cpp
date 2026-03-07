#include "Persistencia.h"
#include <fstream>
#include <iostream>
#include <sstream>

std::vector<Aluno> Persistencia::carregarAlunos(const std::string& arquivo) {
    std::vector<Aluno> alunos;

    std::ifstream file(arquivo);

    if (!file.is_open()) {
        throw std::runtime_error("Arquivo não encontrado ou sem permissão.");
    }

    std::string linha;

    while (std::getline(file, linha)) {
        std::stringstream ss(linha);

        std::string nome;
        std::string senha;

        std::getline(ss, nome, ',');
        std::getline(ss, senha, ',');

        Aluno a(nome, senha);

        alunos.push_back(a);
    }
    
    file.close();

    return alunos;
}

void Persistencia::salvarAlunos(const std::string& arquivo, const std::vector<Aluno>& alunos) {

    std::ofstream file(arquivo);

    if (!file.is_open()) {
        throw std::runtime_error("Erro ao salvar arquivo.");
    }

    for (const auto& a : alunos) {
        file << a.getNome() << "," << a.getSenha() << std::endl;
    }

    file.close();
}