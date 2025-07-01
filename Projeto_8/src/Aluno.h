#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <iostream>

class Aluno {
public:
    std::string nome;
    int matricula;

    friend std::ostream& operator<<(std::ostream& os, const Aluno& a) {
        os << a.matricula << "," << a.nome;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Aluno& a) {
        char delim;
        is >> a.matricula >> delim; 
        std::getline(is, a.nome);
        return is;
    }
};
#endif 