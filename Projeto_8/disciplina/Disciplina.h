#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

//declaraçao da classe disciplina
class Disciplina {
private:
    std::string nome;
    int cargaHoraria;
    float nota;

public:

    //construtor padraão
    Disciplina();
    Disciplina(std::string nome, int cargaHoraria, float nota);

    void setNota(float nota);
    float getNota() const;
    std::string getNome() const { return nome; }
    int getCargaHoraria() const { return cargaHoraria; }
};

bool verificarAprovacao(const Disciplina& disciplina);

#endif 
