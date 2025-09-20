#include "Persistencia.h"
#include <fstream>
#include <iostream>
#include <sstream>

void Persistencia::salvarAlunos(const std::string& nomeArquivo, const std::vector<Aluno*>& alunos) {
    std::ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        throw PermissaoNegadaException();
    }
    arquivo << "Nome,Email,Senha,Matricula,Curso,Historico\n";
    for (const Aluno* aluno : alunos) {
        arquivo << aluno->getNome() << ","
                << aluno->getEmail() << ","
                << "senha_protegida" << ","
                << aluno->getMatricula() << ","
                << aluno->getCurso() << ",";

        const auto& historico = aluno->getHistorico();
        for (size_t i = 0; i < historico.size(); ++i) {
            arquivo << historico[i].nomeDisciplina << ";" << historico[i].anoCursado << ";" << historico[i].nota;
            if (i < historico.size() - 1) {
                arquivo << "|";
            }
        }
        arquivo << "\n";
    }
    arquivo.close();
}

void Persistencia::salvarProfessores(const std::string& nomeArquivo, const std::vector<Professor*>& professores) {
    std::ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        throw PermissaoNegadaException();
    }
    arquivo << "Nome,Email,Senha,AreaDeAtuacao\n";
    // Lógica para salvar professores...
    arquivo.close();
}

std::vector<Aluno*> Persistencia::carregarAlunos(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    std::vector<Aluno*> alunos;
    if (!arquivo.is_open()) {
        throw ArquivoNaoEncontradoException();
    }

    std::string linha;
    std::getline(arquivo, linha);

    while (std::getline(arquivo, linha)) {
        if (linha.empty()) continue;

        std::stringstream ss(linha);
        std::string nome, email, senha, matricula, curso, historicoStr;

        try {
            std::getline(ss, nome, ',');
            std::getline(ss, email, ',');
            std::getline(ss, senha, ',');
            std::getline(ss, matricula, ',');
            std::getline(ss, curso, ',');
            std::getline(ss, historicoStr);

            Aluno* novoAluno = new Aluno(nome, email, senha, matricula, curso);

            if (!historicoStr.empty() && historicoStr != "\r") {
                std::stringstream historicoSS(historicoStr);
                std::string disciplinaStr;
                while(std::getline(historicoSS, disciplinaStr, '|')) {
                    if (disciplinaStr.empty()) continue;

                    std::stringstream disciplinaSS(disciplinaStr);
                    std::string nomeDisc, anoStr, notaStr;

                    std::getline(disciplinaSS, nomeDisc, ';');
                    std::getline(disciplinaSS, anoStr, ';');
                    std::getline(disciplinaSS, notaStr, ';');

                    int ano = std::stoi(anoStr);
                    double nota = std::stod(notaStr);

                    novoAluno->adicionarDisciplinaAoHistorico(nomeDisc, ano, nota);
                }
            }
            alunos.push_back(novoAluno);

        } catch (const std::exception& e) {
            throw FalhaConversaoException(linha);
        }
    }
    arquivo.close();
    return alunos;
}

std::vector<Professor*> Persistencia::carregarProfessores(const std::string& nomeArquivo) {
    std::vector<Professor*> professores;
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        return professores;
    }
    // Lógica para carregar professores aqui...
    arquivo.close();
    return professores;
}
