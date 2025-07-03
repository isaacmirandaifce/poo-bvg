#include "Persistencia.h"
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

vector<Aluno> Persistencia::carregarAlunos(const string& caminhoArquivo) {
    ifstream arquivo(caminhoArquivo);
    if (!arquivo.is_open())
        throw ArquivoNaoEncontradoException("Não foi possível abrir o arquivo: " + caminhoArquivo);

    vector<Aluno> alunos;
    string linha;
    while (getline(arquivo, linha)) {
        // Ignora linhas vazias
        if (linha.find_first_not_of(" \t\r\n") == string::npos)
            continue;

        stringstream ss(linha);
        string nome, email, tipo, senha, matricula, curso, disciplinasRaw;
        getline(ss, nome, ';');
        getline(ss, email, ';');
        getline(ss, tipo, ';');
        getline(ss, senha, ';');
        getline(ss, matricula, ';');
        getline(ss, curso, ';');
        getline(ss, disciplinasRaw, ';');

        if (nome.empty() || matricula.empty())
            throw ErroConversaoException("Erro ao converter dados: linha inválida → " + linha);

        vector<string> disciplinas;
        stringstream sd(disciplinasRaw);
        string disc;
        while (getline(sd, disc, ',')) {
            disciplinas.push_back(disc);
        }

        Aluno aluno(nome, email, tipo, senha, matricula, curso, disciplinas);
        alunos.push_back(aluno);
    }

    arquivo.close();
    return alunos;
}

void Persistencia::salvarAlunos(const string& caminhoArquivo, const vector<Aluno>& alunos) {
    ofstream arquivo(caminhoArquivo);
    if (!arquivo.is_open()) {
        throw PermissaoNegadaException("Não foi possível salvar o arquivo: " + caminhoArquivo);
    }

    for (const auto& aluno : alunos) {
        arquivo << aluno.getNome() << ";"
                << aluno.getEmail() << ";"
                << "Aluno" << ";"
                << "****" << ";"
                << aluno.getMatricula() << ";"
                << aluno.getCurso() << ";";
        
        // Salvar disciplinas separadas por vírgula
        const vector<string>& disciplinas = aluno.getDisciplinas();
        for (size_t i = 0; i < disciplinas.size(); ++i) {
            arquivo << disciplinas[i];
            if (i < disciplinas.size() - 1) {
                arquivo << ",";
            }
        }
        arquivo << ";"; // Terminar com ponto e vírgula
        arquivo << endl;
    }

    arquivo.close();
}

vector<Professor> Persistencia::carregarProfessores(const string& caminhoArquivo) {
    ifstream arquivo(caminhoArquivo);
    if (!arquivo.is_open()) {
        throw ArquivoNaoEncontradoException("Erro ao abrir arquivo de professores: " + caminhoArquivo);
    }

    vector<Professor> professores;
    string linha;
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string nome, email, tipo, senha, area, disciplinasRaw;
        getline(ss, nome, ';');
        getline(ss, email, ';');
        getline(ss, tipo, ';');
        getline(ss, senha, ';');
        getline(ss, area, ';');
        getline(ss, disciplinasRaw, ';');

        if (nome.empty() || area.empty()) {
            throw ErroConversaoException("Erro de conversão de dados (professor): " + linha);
        }

        vector<string> disciplinas;
        stringstream sd(disciplinasRaw);
        string disc;
        while (getline(sd, disc, ',')) {
            disciplinas.push_back(disc);
        }

        Professor p(nome, email, tipo, senha, area, disciplinas);
        professores.push_back(p);
    }

    arquivo.close();
    return professores;
}

void Persistencia::salvarProfessores(const string& caminhoArquivo, const vector<Professor>& professores) {
    ofstream arquivo(caminhoArquivo);
    if (!arquivo.is_open()) {
        throw PermissaoNegadaException("Erro ao salvar arquivo de professores: " + caminhoArquivo);
    }

    for (const auto& p : professores) {
        arquivo << p.getNome() << ";"
                << p.getEmail() << ";"
                << "Professor" << ";"
                << "****" << ";"
                << p.getAreaDeAtuacao() << ";";

        for (const auto& d : p.getDisciplinasMinistradas()) {
            arquivo << d << ",";
        }

        arquivo << endl;
    }


    arquivo.close();
}
