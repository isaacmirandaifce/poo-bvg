#ifndef ALUNO_H
#define ALUNO_H

#include "UsuarioAutenticavel.h"
#include <vector>
#include <string>

// Classe Aluno que herda de UsuarioAutenticavel
class Aluno : public UsuarioAutenticavel {
private:
    std::string matricula;
    std::string curso;
    std::vector<std::string> disciplinasCursadas;

    // Classe interna para o histórico disciplinar
    class HistoricoDisciplinar {
    public:
        std::string nomeDisciplina;
        int anoCursado;
        double nota;

        HistoricoDisciplinar(const std::string& nomeDisciplina, int anoCursado, double nota)
            : nomeDisciplina(nomeDisciplina), anoCursado(anoCursado), nota(nota) {}
    };

    std::vector<HistoricoDisciplinar> historico;

public:
    // Construtor
    Aluno(const std::string& nome, const std::string& email, const std::string& matricula, 
          const std::string& curso, const std::string& senha);

    // Métodos para disciplinas cursadas
    void adicionarDisciplina(const std::string& disciplina);

    // Métodos para histórico disciplinar
    void adicionarHistorico(const std::string& nomeDisciplina, int ano, double nota);

    // Métodos de relatório
    void gerarRelatorio() const override;
    void gerarRelatorio(bool incluirNotas) const; // Sobrecarga

    // Método para autenticação
    bool autenticar(const std::string& senhaTentativa) const override;

    // Método para calcular a média do aluno com base no histórico
    double calcularMedia() const;

    // Método para obter as disciplinas cursadas em um determinado ano
    std::vector<std::string> getDisciplinasPorAno(int ano) const;
};

#endif // ALUNO_H
