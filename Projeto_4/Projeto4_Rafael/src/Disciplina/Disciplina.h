#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

class Disciplina {
private:
    std::string nome;
    int cargaHoraria;
    float nota;

public:
    Disciplina(); // Construtor padrão
    Disciplina(std::string nome, int cargaHoraria); // Construtor parametrizado

    void setNota(float nota);
    float getNota() const;

    void exibirDados() const;

    friend void verificarAprovacao(const Disciplina& d); // Função amiga
};

#endif // DISCIPLINA_H
