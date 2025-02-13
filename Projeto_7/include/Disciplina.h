#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

class Disciplina {
private:
    std::string nome;
    int ano;

public:
    Disciplina(std::string nome, int ano);
    std::string getNome() const;
    int getAno() const;
};

#endif // DISCIPLINA_H