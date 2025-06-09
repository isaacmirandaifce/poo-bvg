#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
using namespace std;

class Disciplina {
private:
    string nome;
    int cargaHoraria;
    float nota;

public:
    Disciplina(); // construtor padrão
    Disciplina(string n, int c); // construtor com parâmetros

    void setNota(float n); // define a nota
    float getNota(); // retorna a nota
    string getNome(); // retorna o nome da disciplina

    friend bool verificarAprovacao(Disciplina d); // função amiga
};

#endif
