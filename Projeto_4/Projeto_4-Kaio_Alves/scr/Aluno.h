#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include "Disciplina.h" // Incluindo a classe Disciplina

namespace std {

class Aluno {
private:
    string nome;
    string matricula;
    string curso;

public:
    // Construtores
    Aluno();
    Aluno(string nome, string matricula, string curso);

    // Destrutor
    ~Aluno();

    // Métodos
    void exibirInformacoes();

    // Método público para obter o nome
    string getNome() const {
        return this->nome;
    }

    friend void verificarAprovacao(Aluno& aluno, Disciplina& disciplina); // Função amiga
};

}

#endif