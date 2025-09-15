#ifndef ALUNO_H
#define ALUNO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <vector>
#include <string>

class Aluno : public UsuarioAutenticavel, public Relatorio {
private:
    std::string curso;
    int periodo;

public:
    // Classe interna para histórico disciplinar
    class HistoricoDisciplinar {
    private:
        std::string nomeDisciplina;
        int anoCursado;
        double nota;

    public:
        HistoricoDisciplinar(const std::string& disciplina, int ano, double nota);

        // Getters
        std::string getNomeDisciplina() const;
        int getAnoCursado() const;
        double getNota() const;

        void exibirHistorico() const;
    };

private:
    std::vector<HistoricoDisciplinar> historico;

public:
    Aluno(const std::string& nome, const std::string& email, int id,
          const std::string& senha, const std::string& curso, int periodo);

    // Métodos específicos do aluno
    void setCurso(const std::string& curso);
    void setPeriodo(int periodo);
    std::string getCurso() const;
    int getPeriodo() const;

    // Método para adicionar disciplina ao histórico
    void adicionarDisciplina(const std::string& disciplina, int ano, double nota);

    // Implementações dos métodos abstratos
    bool autenticar(const std::string& senha) override;
    void gerarRelatorio() const override;

    void exibirInformacoes() const override;
    void exibirHistoricoCompleto() const;
};

#endif
