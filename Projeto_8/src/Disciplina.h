#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include <iostream>

class Disciplina {
public:
    std::string nome;
    std::string codigo;

     friend std::ostream& operator<<(std::ostream& os, const Disciplina& d) {
        os << d.codigo << "," << d.nome;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Disciplina& d) {
        std::getline(is, d.codigo, ',');
        std::getline(is, d.nome);
        return is;
    }
};
#endif