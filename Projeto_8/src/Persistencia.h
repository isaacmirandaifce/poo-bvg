#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <stdexcept>
#include <string>
#include <vector>

#include "Aluno.h"
#include "Professor.h"

class ArquivoNaoEncontradoException : public std::runtime_error {
public:
    explicit ArquivoNaoEncontradoException(const std::string& caminho)
        : std::runtime_error("Arquivo nao encontrado: " + caminho) {}
};

class PermissaoNegadaException : public std::runtime_error {
public:
    explicit PermissaoNegadaException(const std::string& caminho)
        : std::runtime_error("Permissao negada no arquivo: " + caminho) {}
};

class FalhaConversaoException : public std::runtime_error {
public:
    explicit FalhaConversaoException(const std::string& detalhe)
        : std::runtime_error("Falha de conversao: " + detalhe) {}
};

struct DadosAcademicos {
    std::vector<Aluno> alunos;
    std::vector<Professor> professores;
    std::vector<std::string> disciplinas;
};

class Persistencia {
public:
    explicit Persistencia(std::string diretorioBase);

    void carregarTudo(DadosAcademicos& dados) const;
    void salvarTudo(const DadosAcademicos& dados) const;

private:
    std::string diretorioBase;

    std::string caminhoAlunos() const;
    std::string caminhoHistorico() const;
    std::string caminhoProfessores() const;
    std::string caminhoProfessorDisciplinas() const;
    std::string caminhoDisciplinas() const;

    std::vector<std::string> dividirLinha(const std::string& linha, char separador) const;
};

#endif
