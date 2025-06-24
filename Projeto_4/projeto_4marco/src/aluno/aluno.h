#ifndef ALUNO_H
#define ALUNO_H

#include <string>

class Aluno {
private:
    std::string nome;
    std::string matricula;
    std::string curso;

public:
    Aluno(); // Construtor padrão
    Aluno(std::string nome, std::string matricula, std::string curso); // Construtor parametrizado

    void exibirInformacoes() const;
};

#endif // ALUNO_H