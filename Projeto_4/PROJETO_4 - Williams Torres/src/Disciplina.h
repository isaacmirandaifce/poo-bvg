#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

class Disciplina {
private:
    std::string nome;
    int cargaHoraria;
    float nota;

public:
    // Construtores
    Disciplina();
    Disciplina(const std::string& nome, int cargaHoraria, float nota);

    // Métodos
    void setNota(float nota);
    float getNota() const;

    // Função amiga
    friend bool verificarAprovacao(const Disciplina& disciplina);
};

#endif // DISCIPLINA_H
