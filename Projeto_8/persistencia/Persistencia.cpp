#include "Persistencia.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Verifica se o arquivo foi aberto corretamente
void Persistencia::verificarArquivo(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        throw runtime_error("Erro ao abrir o arquivo: " + nomeArquivo);
    }
}

// Carrega os alunos do arquivo "alunos.txt"
vector<Aluno> Persistencia::carregarAlunos() {
    vector<Aluno> alunos;
    ifstream arquivo("alunos.txt");
    verificarArquivo("alunos.txt");

    string nome, id, curso;
    while (getline(arquivo, nome) && getline(arquivo, id) && getline(arquivo, curso)) {
        alunos.push_back(Aluno(nome, id, curso));
    }
    return alunos;
}

// Salva os alunos no arquivo "alunos.txt"
void Persistencia::salvarAlunos(const vector<Aluno>& alunos) {
    ofstream arquivo("alunos.txt");
    if (!arquivo.is_open()) {
        throw runtime_error("Erro ao abrir o arquivo para salvar os alunos.");
    }

    for (const auto& aluno : alunos) {
        arquivo << aluno.getNome() << endl;
        arquivo << aluno.getId() << endl;
        arquivo << aluno.getCurso() << endl;
    }
}

// Carrega as disciplinas do arquivo "disciplinas.txt"
vector<Disciplina> Persistencia::carregarDisciplinas() {
    vector<Disciplina> disciplinas;
    ifstream arquivo("disciplinas.txt");
    verificarArquivo("disciplinas.txt");

    string nome;
    int cargaHoraria;
    float nota;
    while (getline(arquivo, nome) && arquivo >> cargaHoraria >> nota) {
        arquivo.ignore(); // Remove o caractere de nova linha
        disciplinas.push_back(Disciplina(nome, cargaHoraria, nota));
    }
    return disciplinas;
}

// Salva as disciplinas no arquivo "disciplinas.txt"
void Persistencia::salvarDisciplinas(const vector<Disciplina>& disciplinas) {
    ofstream arquivo("disciplinas.txt");
    if (!arquivo.is_open()) {
        throw runtime_error("Erro ao abrir o arquivo para salvar as disciplinas.");
    }

    for (const auto& disciplina : disciplinas) {
        arquivo << disciplina.getNome() << endl;
        arquivo << disciplina.getCargaHoraria() << " " << disciplina.getNota() << endl;
    }
}

// Carrega os professores do arquivo "professores.txt"
vector<Professor> Persistencia::carregarProfessores() {
    vector<Professor> professores;
    ifstream arquivo("professores.txt");
    verificarArquivo("professores.txt");

    string nome, id, disciplina;
    while (getline(arquivo, nome) && getline(arquivo, id) && getline(arquivo, disciplina)) {
        professores.push_back(Professor(nome, id, disciplina));
    }
    return professores;
}

// Salva os professores no arquivo "professores.txt"
void Persistencia::salvarProfessores(const vector<Professor>& professores) {
    ofstream arquivo("professores.txt");
    if (!arquivo.is_open()) {
        throw runtime_error("Erro ao abrir o arquivo para salvar os professores.");
    }

    for (const auto& professor : professores) {
        arquivo << professor.getNome() << endl;
        arquivo << professor.getId() << endl;
        arquivo << professor.getDisciplina() << endl;
    }
}
