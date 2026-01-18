#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <string>
#include <vector>
#include <stdexcept>

#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"

class ArquivoNaoEncontradoException : public std::runtime_error {
public:
    ArquivoNaoEncontradoException(const std::string& msg) : std::runtime_error(msg) {}
};

class PermissaoNegadaException : public std::runtime_error {
public:
    PermissaoNegadaException(const std::string& msg) : std::runtime_error(msg) {}
};

class ConversaoDadosException : public std::runtime_error {
public:
    ConversaoDadosException(const std::string& msg) : std::runtime_error(msg) {}
};

class Persistencia {
public:
    static std::vector<Aluno> carregarAlunos(const std::string& caminho);
    static void salvarAlunos(const std::string& caminho, const std::vector<Aluno>& alunos);

    static std::vector<Professor> carregarProfessores(const std::string& caminho);
    static void salvarProfessores(const std::string& caminho, const std::vector<Professor>& profs);

    static std::vector<Disciplina> carregarDisciplinas(const std::string& caminho);
    static void salvarDisciplinas(const std::string& caminho, const std::vector<Disciplina>& disciplinas);
};

#endif // PERSISTENCIA_H
