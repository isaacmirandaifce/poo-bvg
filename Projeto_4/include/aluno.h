#ifndef ALUNO_H
#define ALUNO_H
#include <string>
#include <iostream>

class Aluno {
private:
    std::string nome;
    std::string matricula;
    std::string curso;

public:
    Aluno(std::string nome, std::string matricula, std::string curso);
    ~Aluno();  // Apenas a declaração do destruidor
    void exibirInformacoes() const;  // Apenas a declaração do método
};

#endif
