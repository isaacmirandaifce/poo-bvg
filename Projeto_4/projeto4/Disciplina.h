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
    Disciplina(std::string nome, int cargaHoraria);

    void setNota(float nota);
    float getNota();
    std::string getNome();

    // Função amiga para verificação de status
    friend bool verificarAprovacao(const Disciplina &d);
};

#endif
