#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include <iostream>

class Disciplina {
private:
    std::string nome;
    int ano;

public:
    Disciplina(std::string n = "", int a = 0) 
        : nome(n), ano(a) {}

    std::string getNome() const { return nome; }
    int getAno() const { return ano; }

    void imprimir() const {
        std::cout << "Disciplina: " << nome 
                  << " | Ano: " << ano << std::endl;
    }
};

#endif
