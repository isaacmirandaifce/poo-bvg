#ifndef ALUNO_H
#define ALUNO_H

#include "UsuarioAutenticavel.h"
#include <vector>

using namespace std;

class Aluno : public UsuarioAutenticavel {
public:
    class HistoricoDisciplinar {
    private:
        string disciplina;
        int ano;
        float nota;

    public:
        HistoricoDisciplinar(string d, int a, float n) {
            disciplina = d;
            ano = a;
            nota = n;
        }

        void exibir() const {
            cout << "- " << disciplina << " (" << ano << ") Nota: " << nota << endl;
        }
        float getNota() const { return nota; }
        int getAno() const { return ano; }
        string getDisciplina() const { return disciplina; }
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
    const std::vector<HistoricoDisciplinar>& getHistorico() const;

};

#endif
