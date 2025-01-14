// Disciplina.h
#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

class Disciplina {
private:
    std::string nome;
    int cargaHoraria;
    float nota;

    // Declaração de função amiga
    friend bool verificarAprovacao(const Disciplina& disciplina);

public:
    // Construtores
    Disciplina();
    Disciplina(const std::string& nome, int cargaHoraria, float nota);

    // Métodos
    void setNota(float nota);
    float getNota() const;

    // Getters
    const std::string& getNome() const;
    int getCargaHoraria() const;
};

#endif // DISCIPLINA_H
