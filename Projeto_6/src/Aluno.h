#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include "Disciplina.h"

class Aluno : public UsuarioAutenticavel, public Relatorio {
public:
    // classe interna para histórico disciplinar
    class HistoricoDisciplinar {
    private:
        std::string nomeDisciplina;
        int ano;
        float nota;
    public:
        HistoricoDisciplinar(const std::string& nome, int ano, float nota)
            : nomeDisciplina(nome), ano(ano), nota(nota) {}
        const std::string& getNome() const { return nomeDisciplina; }
        int getAno() const { return ano; }
        float getNota() const { return nota; }
    };

private:
    std::string matricula;
    std::string curso;
    std::vector<Disciplina> disciplinas;
    std::vector<HistoricoDisciplinar> historico;
    std::size_t senhaHash;

public:
    Aluno();
    Aluno(const std::string& nome, const std::string& email, const std::string& matricula,
          const std::string& curso);

    void setSenha(const std::string& senha);
    bool autenticar(const std::string& senha) const override;

    void gerarRelatorio() const override;

    void adicionarDisciplina(const Disciplina& d);
    void adicionarHistorico(const std::string& nome, int ano, float nota);
    void exibirDisciplinas() const;
    const std::string& getMatricula() const;
    const std::string& getCurso() const;
};

#endif // ALUNO_H
