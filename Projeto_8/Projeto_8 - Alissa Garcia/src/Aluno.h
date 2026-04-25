#ifndef ALUNO_H
#define ALUNO_H

#include "UsuarioAutenticavel.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Aluno : public UsuarioAutenticavel {
public:
    class HistoricoDisciplinar {
    private:
        string disciplina;
        int ano;
        float nota;

    public:
        HistoricoDisciplinar(string d, int a, float n);

        void exibir() const;

        float getNota() const;
        int getAno() const;
        string getDisciplina() const;
    };

private:
    string matricula;
    string curso;
    vector<HistoricoDisciplinar> historico;

public:
    Aluno();
    Aluno(string nome, string email, string senha, string matricula, string curso);

    void adicionarHistorico(string disciplina, int ano, float nota);
    bool autenticar(string senha) override;
    void gerarRelatorio() const override;
    float calcularMedia() const;
    const vector<HistoricoDisciplinar>& getHistorico() const;

    // ✅ GETTERS NECESSÁRIOS PARA A PERSISTÊNCIA
    string getMatricula() const;
    string getCurso() const;
};

#endif
