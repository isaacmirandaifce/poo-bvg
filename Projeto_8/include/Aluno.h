#ifndef ALUNO_H
#define ALUNO_H

#include <string>

class Aluno {
public:
    Aluno(int id, const std::string& nome);
    int getId() const;
    std::string getNome() const;

private:
    int id;
    std::string nome;
};

#endif // ALUNO_H