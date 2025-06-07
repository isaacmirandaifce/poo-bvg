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
    Disciplina(string n, int ch, float nt);

    void setNota(float nt);
    float getNota() const;
    string getNome() const;

    friend bool verificarAprovacao(const Disciplina& d); // função amiga
};

#endif // DISCIPLINA_H