#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

class Disciplina {
private:
    std::string nome;
    int cargaHoraria;
    float nota;

public:
    Disciplina();
    Disciplina(const std::string& nome, int cargaHoraria, float nota = 0.0f);

    void setNota(float nota);
    float getNota() const;
    std::string getNome() const;
    int getCargaHoraria() const;

    friend bool aprovado(const Disciplina& d);
};

#endif
