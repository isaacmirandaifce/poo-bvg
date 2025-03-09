#include "Persistencia.h"
#include <iostream>
#include <sstream>

void Persistencia::salvarAlunos(const std::vector<Aluno>& alunos, const std::string& arquivo) {
    std::ofstream file(arquivo);
    if (!file.is_open()) {
        throw ArquivoNaoEncontradoException("Erro ao abrir o arquivo para escrita: " + arquivo);
    }

    for (const auto& aluno : alunos) {
        file << aluno.getNome() << "," << aluno.getMatricula() << "," << aluno.getCurso() << "," << aluno.getMedia() << "\n";
    }
    file.close();
}

std::vector<Aluno> Persistencia::carregarAlunos(const std::string& arquivo) {
    std::ifstream file(arquivo);
    if (!file.is_open()) {
        throw ArquivoNaoEncontradoException("Erro ao abrir o arquivo para leitura: " + arquivo);
    }

    std::vector<Aluno> alunos;
    std::string linha;
    while (std::getline(file, linha)) {
        std::stringstream ss(linha);
        std::string nome, matricula, curso;
        double media;
        std::getline(ss, nome, ',');
        std::getline(ss, matricula, ',');
        std::getline(ss, curso, ',');
        ss >> media;
        alunos.push_back(Aluno(nome, matricula, curso, "senha", media)); // Senha padrão
    }
    file.close();
    return alunos;
}

void Persistencia::salvarProfessores(const std::vector<Professor>& professores, const std::string& arquivo) {
    std::ofstream file(arquivo);
    if (!file.is_open()) {
        throw ArquivoNaoEncontradoException("Erro ao abrir o arquivo para escrita: " + arquivo);
    }

    for (const auto& professor : professores) {
        file << professor.getNome() << "," << professor.getDisciplina() << "\n";
    }
    file.close();
}

std::vector<Professor> Persistencia::carregarProfessores(const std::string& arquivo) {
    std::ifstream file(arquivo);
    if (!file.is_open()) {
        throw ArquivoNaoEncontradoException("Erro ao abrir o arquivo para leitura: " + arquivo);
    }

    std::vector<Professor> professores;
    std::string linha;
    while (std::getline(file, linha)) {
        std::stringstream ss(linha);
        std::string nome, disciplina;
        std::getline(ss, nome, ',');
        std::getline(ss, disciplina, ',');
        professores.push_back(Professor(nome, disciplina, "senha")); // Senha padrão
    }
    file.close();
    return professores;
}