#ifndef ALUNO_H
#define ALUNO_H

#include <string>

class Aluno {
private:
    int id;
    std::string nome;

public:
    Aluno();
    Aluno(int id, const std::string& nome);

    int getId() const;
    std::string getNome() const;

    std::string toString() const;
    static Aluno fromString(const std::string& linha);
};

#endif
