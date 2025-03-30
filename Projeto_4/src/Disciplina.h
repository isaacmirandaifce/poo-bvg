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

    void setNota(float novaNota);
    float getNota() const;

    std::string getNome() const;

    // Declaração de função amiga
    friend bool verificarAprovacao(const Disciplina& disciplina);
};

#endif 
