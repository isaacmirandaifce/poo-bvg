#ifndef ALUNO_H
#define ALUNO_H

#include <string>

class Aluno {
private:
    std::string nome;
    double media;

public:
    Aluno(std::string nome, double media);
    std::string getNome() const;
    double getMedia() const;
};

#endif // ALUNO_H