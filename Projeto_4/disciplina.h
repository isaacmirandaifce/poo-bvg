#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>


//definindo a classe diciplina
class Disciplina {
private:
    std::string nome;
    int cargaHoraria;
    float nota;

public:
    Disciplina();
    Disciplina(std::string nome, int cargaHoraria, float nota);

    //definindo nota
    void setNota(float nota);
    //obtendo nota
    float getNota() const;

    //verificando aprovação do aluno
    friend bool verificarAprovacao(const Disciplina& disciplina);
};

#endif
