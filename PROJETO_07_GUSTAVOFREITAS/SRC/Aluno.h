#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class Aluno : public UsuarioAutenticavel, public Relatorio {
private:
    std::string curso;

    // Classe interna para histórico disciplinar
    class HistoricoDisciplinar {
    private:
        std::string nomeDisciplina;
        int ano;
        double nota;

    public:
        HistoricoDisciplinar(const std::string& nomeDisciplina, int ano, double nota);
        
        std::string getNomeDisciplina() const;
        int getAno() const;
        double getNota() const;
        void setNota(double novaNota);
    };

    std::vector<HistoricoDisciplinar> historico;

public:
    Aluno(const std::string& nome, const std::string& email,
          const std::string& matricula, const std::string& senha,
          const std::string& curso);

    void adicionarDisciplina(const std::string& nomeDisciplina, int ano, double nota);
    double calcularMedia() const;
    void gerarRelatorio() const override;

    std::string getCurso() const;
    void setCurso(const std::string& curso);
};

// Adições para o Projeto 7
std::ostream& operator<<(std::ostream& os, const Aluno& aluno);
std::ostream& operator<<(std::ostream& os, const Aluno::HistoricoDisciplinar& historico);

#endif // ALUNO_H