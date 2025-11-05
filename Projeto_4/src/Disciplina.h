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
    void setNota(float n);
    float getNota() const;
    const std::string& getNome() const;
    int getCargaHoraria() const;

    // função amiga que verifica aprovação (acessa atributo privado `nota`)
    friend bool verificarAprovacao(const Disciplina& d);
};

#endif // DISCIPLINA_H
