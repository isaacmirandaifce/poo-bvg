#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include <iostream>

class Disciplina {
private:
    std::string nome;
    int cargaHoraria;
    float nota;

public:
    Disciplina();
    Disciplina(std::string nome, int cargaHoraria);

    void setNota(float nota);
    float getNota() const;

    friend void verificarAprovacao(const Disciplina& d);
};

#endif
