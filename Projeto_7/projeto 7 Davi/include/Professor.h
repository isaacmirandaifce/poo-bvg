#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <iostream>

class Professor {
private:
    std::string nome;
    std::string disciplinaMinistrada;

public:
    Professor(const std::string& nome, const std::string& disciplinaMinistrada);

    const std::string& getNome() const;
    const std::string& getDisciplinaMinistrada() const;

    void imprimir() const;
};

#endif
