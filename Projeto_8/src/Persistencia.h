#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include "Aluno.h"
#include "Professor.h"

class Persistencia {
public:
    static std::vector<std::shared_ptr<Aluno>> carregarAlunos(const std::string& caminho);
    static void salvarAlunos(const std::vector<std::shared_ptr<Aluno>>& alunos, const std::string& caminho);

    static std::vector<std::shared_ptr<Professor>> carregarProfessores(const std::string& caminho);
    static void salvarProfessores(const std::vector<std::shared_ptr<Professor>>& professores, const std::string& caminho);
};

class ArquivoNaoEncontradoException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Arquivo nao encontrado.";
    }
};

class PermissaoNegadaException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Permissao negada para acessar o arquivo.";
    }
};

class ErroConversaoDadosException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erro na conversao dos dados.";
    }
};

#endif // PERSISTENCIA_H
