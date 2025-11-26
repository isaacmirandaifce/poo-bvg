#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <vector>

class Aluno : public Usuario {
private:
    string matricula;
    string curso;
    // disciplinas podem ser apenas nomes para simplicidade
    vector<string> disciplinas;
    // optional: notas por disciplina (map ou parallel vectors). Para exercício, usamos sobrecarga para mostrar com/sem notas.

public:
    Aluno();
    Aluno(const string &nome, const string &email, const string &matricula, const string &curso);
    ~Aluno();

    void adicionarDisciplina(const string &disciplina);
    // sobrescrita de gerarRelatorio
    void gerarRelatorio() const override;

    // sobrecarga: exibir com e sem notas (aqui sem implementar estrutura de notas completa; assinatura demonstrativa)
    void exibirInformacoes() const;                 // sem notas
    void exibirInformacoes(const vector<float> &notas) const; // com notas (sobrecarga)

    string getMatricula() const;
    string getCurso() const;
    const vector<string>& getDisciplinas() const;
};

#endif // ALUNO_H