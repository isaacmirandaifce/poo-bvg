#ifndef ALUNO_H
#define ALUNO_H

#include <string>

class Aluno {
private:
    std::string nome;
    double media;
    int ano;

public:
    Aluno();
    Aluno(std::string nome, double media, int ano);

    std::string getNome() const;
    double getMedia() const;
    int getAno() const;
};

#endif
