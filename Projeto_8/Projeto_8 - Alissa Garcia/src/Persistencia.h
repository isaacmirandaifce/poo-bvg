#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <string>
#include <vector>
#include <exception>
#include <mutex>
#include "Aluno.h"
#include "Professor.h"

class PersistenciaException : public std::exception {
public:
    explicit PersistenciaException(const std::string &msg) : _msg(msg) {}
    const char* what() const noexcept override { return _msg.c_str(); }
private:
    std::string _msg;
};

class ArquivoNaoEncontradoException : public PersistenciaException {
public:
    explicit ArquivoNaoEncontradoException(const std::string &f)
        : PersistenciaException("Arquivo não encontrado: " + f) {}
};

class PermissaoNegadaException : public PersistenciaException {
public:
    explicit PermissaoNegadaException(const std::string &f)
        : PersistenciaException("Permissão negada: " + f) {}
};

class ConversaoDadosException : public PersistenciaException {
public:
    explicit ConversaoDadosException(const std::string &msg)
        : PersistenciaException("Erro de conversão: " + msg) {}
};

class Persistencia {
public:
    explicit Persistencia(const std::string& pastaDados = "data");

    // Carrega os arquivos (lança exceções em caso de erro)
    void carregar();

    // Salva os arquivos (lança exceções em caso de erro)
    void salvar();

    // Versão "melhor esforço" para chamarmos a partir do tratador de sinais.
    // Não é garantido ser 100% segura em todos os SOs; é uma tentativa controlada.
    void salvarEmSituacaoDeSinal() noexcept;

    // APIs para manipular dados. Chamam salvar() automaticamente (persistência imediata).
    void adicionarAluno(const Aluno& a);
    void adicionarProfessor(const Professor& p);
    void adicionarDisciplina(const std::string& d);

    // getters (cópia)
    std::vector<Aluno> listarAlunos();
    std::vector<Professor> listarProfessores();
    std::vector<std::string> listarDisciplinas();

private:
    std::string pasta;
    std::vector<Aluno> alunos;
    std::vector<Professor> professores;
    std::vector<std::string> disciplinas;

    std::mutex mtx;

    void carregarAlunos(const std::string& caminho);
    void carregarProfessores(const std::string& caminho);
    void carregarDisciplinas(const std::string& caminho);

    void salvarAlunos(const std::string& caminho);
    void salvarProfessores(const std::string& caminho);
    void salvarDisciplinas(const std::string& caminho);

    // helpers
    static std::vector<std::string> split(const std::string& s, char sep);
    static std::string join(const std::vector<std::string>& parts, char sep);
};

#endif // PERSISTENCIA_H
