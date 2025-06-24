#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include <iostream>

class Disciplina {
private:
    std::string nome;
    int cargaHoraria;
    float nota;

public:
    Disciplina();  
    Disciplina(const std::string& nome, int cargaHoraria, float nota);  // Construtor com parâmetros

    void setNota(float novaNota);
    float getNota() const;

    friend void verificarAprovacao(const Disciplina& d);  // Função amiga
};

#endif 
