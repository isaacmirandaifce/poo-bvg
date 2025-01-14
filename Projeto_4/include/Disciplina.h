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
    Disciplina(const std::string& nome, int cargaHoraria);

    void setNota(float nota);
    float getNota() const;

    friend bool verificarAprovacao(const Disciplina& disciplina);
};

#endif
