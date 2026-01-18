#include "Persistencia.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

std::vector<Aluno> Persistencia::carregarAlunos(const std::string& caminho) {
    if (!std::filesystem::exists(caminho)) {
        throw ArquivoNaoEncontradoException("Arquivo de alunos não encontrado: " + caminho);
    }
    std::ifstream in(caminho);
    if (!in) {
        throw PermissaoNegadaException("Não foi possível abrir arquivo de leitura: " + caminho);
    }

    std::vector<Aluno> resultado;
    std::string linha;
    while (std::getline(in, linha)) {
        if (linha.empty()) continue;
        std::istringstream ss(linha);
        std::string nome, email, matricula, curso;
        if (!std::getline(ss, nome, ';') || !std::getline(ss, email, ';') ||
            !std::getline(ss, matricula, ';') || !std::getline(ss, curso, ';')) {
            throw ConversaoDadosException("Linha de aluno com formato inválido: " + linha);
        }
        Aluno a(nome, email, matricula, curso);
        resultado.push_back(a);
    }
    return resultado;
}

void Persistencia::salvarAlunos(const std::string& caminho, const std::vector<Aluno>& alunos) {
    std::ofstream out(caminho);
    if (!out) {
        throw PermissaoNegadaException("Não foi possível abrir arquivo para escrita: " + caminho);
    }
    for (const auto& a : alunos) {
        out << a.getNome() << ";" << a.getEmail() << ";" << a.getMatricula() << ";" << a.getCurso() << "\n";
    }
}

std::vector<Professor> Persistencia::carregarProfessores(const std::string& caminho) {
    std::ifstream in(caminho);
    if (!in) {
        throw ArquivoNaoEncontradoException("Arquivo de professores não encontrado: " + caminho);
    }
    std::vector<Professor> resultado;
    std::string linha;
    while (std::getline(in, linha)) {
        if (linha.empty()) continue;
        std::istringstream ss(linha);
        std::string nome, email, area, disciplinasStr;
        if (!std::getline(ss, nome, ';') || !std::getline(ss, email, ';') || !std::getline(ss, area, ';') || !std::getline(ss, disciplinasStr, ';')) {
            throw ConversaoDadosException("Linha de professor com formato inválido: " + linha);
        }
        std::vector<std::string> disciplinas;
        std::istringstream ds(disciplinasStr);
        std::string token;
        while (std::getline(ds, token, '|')) {
            if (!token.empty()) disciplinas.push_back(token);
        }
        Professor p(nome, email, area, disciplinas);
        resultado.push_back(p);
    }
    return resultado;
}

void Persistencia::salvarProfessores(const std::string& caminho, const std::vector<Professor>& profs) {
    std::ofstream out(caminho);
    if (!out) {
        throw PermissaoNegadaException("Não foi possível abrir arquivo para escrita: " + caminho);
    }
    for (const auto& p : profs) {
        out << p.getNome() << ";" << p.getEmail() << ";";
        out << p.getAreaDeAtuacao() << ";";
        const auto& d = p.getDisciplinasMinistradas();
        for (size_t i = 0; i < d.size(); ++i) {
            out << d[i];
            if (i + 1 < d.size()) out << "|";
        }
        out << "\n";
    }
}

std::vector<Disciplina> Persistencia::carregarDisciplinas(const std::string& caminho) {
    std::ifstream in(caminho);
    if (!in) {
        throw ArquivoNaoEncontradoException("Arquivo de disciplinas não encontrado: " + caminho);
    }
    std::vector<Disciplina> resultado;
    std::string linha;
    while (std::getline(in, linha)) {
        if (linha.empty()) continue;
        std::istringstream ss(linha);
        std::string nome, cargaStr, notaStr;
        if (!std::getline(ss, nome, ';') || !std::getline(ss, cargaStr, ';') || !std::getline(ss, notaStr, ';')) {
            throw ConversaoDadosException("Linha de disciplina com formato inválido: " + linha);
        }
        try {
            int carga = std::stoi(cargaStr);
            float nota = std::stof(notaStr);
            Disciplina d(nome, carga, nota);
            resultado.push_back(d);
        } catch (...) {
            throw ConversaoDadosException("Erro ao converter números na linha: " + linha);
        }
    }
    return resultado;
}

void Persistencia::salvarDisciplinas(const std::string& caminho, const std::vector<Disciplina>& disciplinas) {
    std::ofstream out(caminho);
    if (!out) {
        throw PermissaoNegadaException("Não foi possível abrir arquivo para escrita: " + caminho);
    }
    for (const auto& d : disciplinas) {
        out << d.getNome() << ";" << d.getCargaHoraria() << ";" << d.getNota() << "\n";
    }
}
