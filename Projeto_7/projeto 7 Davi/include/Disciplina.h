#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include <iostream>

class Disciplina {
private:
    std::string nome;
    int ano;

public:
    Disciplina(const std::string& nome, int ano);

    const std::string& getNome() const;
    int getAno() const;

    void imprimir() const;
};

#endif
