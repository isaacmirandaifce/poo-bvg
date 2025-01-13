#ifndef ALUNO_H
#define ALUNO_H

#include <string>

class Aluno {
private:
    std::string nome;
    std::string matricula;
    std::string curso;

public:
    /* Construtores */
    Aluno();
    Aluno(std::string nome, std::string matricula, std::string curso);

    /* Métodos */
    void exibirInformacoes() const;

    /* Getters */
    std::string getNome() const;
    std::string getMatricula() const;
    std::string getCurso() const;
};

#endif /* ALUNO_H */
