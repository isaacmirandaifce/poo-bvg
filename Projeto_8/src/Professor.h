#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <iostream>

class Professor {
public:
    std::string nome;
    int id;

     friend std::ostream& operator<<(std::ostream& os, const Professor& p) {
        os << p.id << "," << p.nome;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Professor& p) {
        char delim;
        is >> p.id >> delim;
        std::getline(is, p.nome);
        return is;
    }
};
#endif