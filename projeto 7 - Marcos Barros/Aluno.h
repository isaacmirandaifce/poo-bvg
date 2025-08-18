#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <iostream>

class Aluno {
private:
    std::string nome;
    double media;
    int anoIngresso;

public:
    Aluno(std::string n = "", double m = 0.0, int ano = 0) 
        : nome(n), media(m), anoIngresso(ano) {}

    std::string getNome() const { return nome; }
    double getMedia() const { return media; }
    int getAnoIngresso() const { return anoIngresso; }

    void imprimir() const {
        std::cout << "Aluno: " << nome 
                  << " | Média: " << media 
                  << " | Ano: " << anoIngresso << std::endl;
    }
};

#endif
