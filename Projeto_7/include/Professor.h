#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>

class Professor {
private:
    std::string nome;
    std::string disciplina;

public:
    Professor(std::string nome, std::string disciplina);
    std::string getNome() const;
    std::string getDisciplina() const;
};

#endif // PROFESSOR_H