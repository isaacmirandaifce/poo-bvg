#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"

// Exceções personalizadas
class ArquivoNaoEncontradoException : public std::exception {
private:
    std::string mensagem;
public:
    ArquivoNaoEncontradoException(const std::string& arquivo)
        : mensagem("Arquivo não encontrado: " + arquivo) {}

    const char* what() const noexcept override {
        return mensagem.c_str();
    }
};

class PermissaoNegadaException : public std::exception {
private:
    std::string mensagem;
public:
    PermissaoNegadaException(const std::string& arquivo)
        : mensagem("Permissão negada para acessar: " + arquivo) {}

    const char* what() const noexcept override {
        return mensagem.c_str();
    }
};

class FalhaConversaoException : public std::exception {
private:
    std::string mensagem;
public:
    FalhaConversaoException(const std::string& dado)
        : mensagem("Falha na conversão do dado: " + dado) {}

    const char* what() const noexcept override {
        return mensagem.c_str();
    }
};

class Persistencia {
public:
    // Métodos para salvar dados
    static void salvarAlunos(const std::vector<Aluno>& alunos, const std::string& arquivo = "alunos.csv");
    static void salvarProfessores(const std::vector<Professor>& professores, const std::string& arquivo = "professores.csv");
    static void salvarDisciplinas(const std::vector<Disciplina>& disciplinas, const std::string& arquivo = "disciplinas.csv");

    // Métodos para carregar dados
    static std::vector<Aluno> carregarAlunos(const std::string& arquivo = "alunos.csv");
    static std::vector<Professor> carregarProfessores(const std::string& arquivo = "professores.csv");
    static std::vector<Disciplina> carregarDisciplinas(const std::string& arquivo = "disciplinas.csv");

private:
    static void verificarArquivo(const std::string& arquivo, std::ios_base::openmode modo);
    static std::vector<std::string> split(const std::string& str, char delimiter);
    static int stringParaInt(const std::string& str);
    static double stringParaDouble(const std::string& str);
};

#endif
