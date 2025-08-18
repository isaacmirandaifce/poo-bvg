#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <iostream>

class Professor {
private:
    std::string nome;
    std::string disciplina;

public:
    Professor(std::string n = "", std::string d = "") 
        : nome(n), disciplina(d) {}

    std::string getNome() const { return nome; }
    std::string getDisciplina() const { return disciplina; }

    void imprimir() const {
        std::cout << "Professor: " << nome 
                  << " | Disciplina: " << disciplina << std::endl;
    }
};

#endif
