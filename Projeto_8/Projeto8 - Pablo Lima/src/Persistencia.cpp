#include "Persistencia.h"
#include <iostream>
#include <fstream>
#include <sstream>

Persistencia::Persistencia() {
    nomeArquivo = "dados_alunos.txt";  
}

void Persistencia::salvarAlunos(const std::vector<Aluno>& alunos) {
    std::ofstream arquivo(nomeArquivo);  

    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo para escrita." << std::endl;
        return;
    }

    for (const auto& aluno : alunos) {
        arquivo << aluno.getNome() << ","
                << aluno.getEmail() << ","
                << aluno.getCurso() << ","
                << aluno.getMedia() << "\n"; 
    }

    arquivo.close();
}

std::vector<Aluno> Persistencia::carregarAlunos() {
    std::vector<Aluno> alunos;
    std::ifstream arquivo(nomeArquivo);  

    if (!arquivo) {
        std::cerr << "Arquivo de alunos não encontrado. Criando um novo." << std::endl;
        return alunos;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string nome, email, curso;
        double media;

        std::getline(ss, nome, ',');
        std::getline(ss, email, ',');
        std::getline(ss, curso, ',');
        ss >> media;

        alunos.emplace_back(nome, email, "senhaPadrao", curso, media); 
    }

    arquivo.close();
    return alunos;
}