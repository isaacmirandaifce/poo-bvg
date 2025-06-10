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
    Disciplina(std::string nome, int cargaHoraria, float nota); // Construtor parametrizado

    void setNota(float n);
    float getNota() const;
    void exibirDados() const;

    // Função amiga para verificar aprovação
    friend bool verificarAprovacao(const Disciplina& d);
};

#endif // DISCIPLINA_H
