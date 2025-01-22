#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

// Declaração antecipada da classe Aluno
namespace std {

class Aluno;  // Declaração antecipada

class Disciplina {
private:
    string nome;
    int cargaHoraria;
    float nota;

public:
    // Construtores
    Disciplina();
    Disciplina(string nome, int cargaHoraria);

    // Métodos
    void setNota(float nota);
    float getNota();

    // Função amiga para verificar aprovação
    friend void verificarAprovacao(Aluno& aluno, Disciplina& disciplina);
};

}

#endif