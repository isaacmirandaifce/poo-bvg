#include "Persistencia.h"
#include <iostream>

std::vector<Aluno> Persistencia::carregarAlunos(const std::string& caminhoArquivo) {
    std::ifstream arquivo(caminhoArquivo);
    verificarErrosArquivo(arquivo, caminhoArquivo);

    std::vector<Aluno> alunos;
    int id;
    std::string nome;
    while (arquivo >> id >> std::ws && std::getline(arquivo, nome)) {
        alunos.emplace_back(id, nome);
    }

    return alunos;
}

void Persistencia::salvarAlunos(const std::string& caminhoArquivo, const std::vector<Aluno>& alunos) {
    std::ofstream arquivo(caminhoArquivo);
    verificarErrosArquivo(arquivo, caminhoArquivo);

    for (const auto& aluno : alunos) {
        arquivo << aluno.getId() << " " << aluno.getNome() << "\n";
    }
}

std::vector<Professor> Persistencia::carregarProfessores(const std::string& caminhoArquivo) {
    std::ifstream arquivo(caminhoArquivo);
    verificarErrosArquivo(arquivo, caminhoArquivo);

    std::vector<Professor> professores;
    int id;
    std::string nome;
    while (arquivo >> id >> std::ws && std::getline(arquivo, nome)) {
        professores.emplace_back(id, nome);
    }

    return professores;
}

void Persistencia::salvarProfessores(const std::string& caminhoArquivo, const std::vector<Professor>& professores) {
    std::ofstream arquivo(caminhoArquivo);
    verificarErrosArquivo(arquivo, caminhoArquivo);

    for (const auto& professor : professores) {
        arquivo << professor.getId() << " " << professor.getNome() << "\n";
    }
}

std::vector<Disciplina> Persistencia::carregarDisciplinas(const std::string& caminhoArquivo) {
    std::ifstream arquivo(caminhoArquivo);
    verificarErrosArquivo(arquivo, caminhoArquivo);

    std::vector<Disciplina> disciplinas;
    int id, professorId;
    std::string nome;
    while (arquivo >> id >> std::ws && std::getline(arquivo, nome) >> professorId) {
        disciplinas.emplace_back(id, nome, professorId);
    }

    return disciplinas;
}

void Persistencia::salvarDisciplinas(const std::string& caminhoArquivo, const std::vector<Disciplina>& disciplinas) {
    std::ofstream arquivo(caminhoArquivo);
    verificarErrosArquivo(arquivo, caminhoArquivo);

    for (const auto& disciplina : disciplinas) {
        arquivo << disciplina.getId() << " " << disciplina.getNome() << " " << disciplina.getProfessorId() << "\n";
    }
}

void Persistencia::verificarErrosArquivo(const std::ifstream& arquivo, const std::string& caminhoArquivo) {
    if (!arquivo.is_open()) {
        throw ArquivoNaoEncontradoException("Arquivo não encontrado: " + caminhoArquivo);
    }
    if (arquivo.fail()) {
        throw PermissaoNegadaException("Permissão negada para abrir o arquivo: " + caminhoArquivo);
    }
}

void Persistencia::verificarErrosArquivo(const std::ofstream& arquivo, const std::string& caminhoArquivo) {
    if (!arquivo.is_open()) {
        throw ArquivoNaoEncontradoException("Arquivo não encontrado: " + caminhoArquivo);
    }
    if (arquivo.fail()) {
        throw PermissaoNegadaException("Permissão negada para abrir o arquivo: " + caminhoArquivo);
    }
}