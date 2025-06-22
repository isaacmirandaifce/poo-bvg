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
    Disciplina();
    Disciplina(string n, int ch);
    void setNota(float n);
    float getNota() const;

    friend void verificarAprovacao(const Disciplina& d); // função amiga
};

#endif
