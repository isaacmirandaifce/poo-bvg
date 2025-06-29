#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include <iostream>

class Disciplina {
private:
    std::string nome;
    int ano;

public:
    Disciplina(std::string nome, int ano) : nome(nome), ano(ano) {}

    std::string getNome() const { return nome; }
    int getAno() const { return ano; }

    void imprimir() const {
        std::cout << "Disciplina: " << nome << " (" << ano << ")" << std::endl;
    }
};

#endif