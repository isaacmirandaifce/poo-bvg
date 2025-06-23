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
    Disciplina(const std::string& nome, int cargaHoraria, float nota);

    void setNota(float n);
    float getNota() const;
    std::string getNome() const;
};

bool verificarAprovacao(const Disciplina& d);

#endif
