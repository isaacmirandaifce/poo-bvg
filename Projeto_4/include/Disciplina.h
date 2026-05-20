#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

class Disciplina {
private:
    std::string nome;
    int cargaHoraria;
    float nota;

public:
    // Construtor padrão
    Disciplina();

    // Construtor parametrizado
    Disciplina(std::string nome, int cargaHoraria, float nota);

    // Setter e getter da nota
    void setNota(float nota);
    float getNota() const;

    // Getter do nome
    std::string getNome() const;

    // Getter da carga horária
    int getCargaHoraria() const;

    // Declaração da função amiga para verificar aprovação
    friend bool verificarAprovacao(const Disciplina& disciplina);
};

#endif // DISCIPLINA_H
