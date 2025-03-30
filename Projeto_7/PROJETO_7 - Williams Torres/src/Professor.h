#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <iostream>

class Professor {
private:
    std::string nome;
    std::string disciplina;

public:
    Professor(const std::string& nome, const std::string& disciplina) : nome(nome), disciplina(disciplina) {}

    std::string getNome() const { return nome; }
    std::string getDisciplina() const { return disciplina; }

    void imprimir() const {
        std::cout << "Professor: " << nome << ", Disciplina: " << disciplina << std::endl;
    }
};

#endif // PROFESSOR_H