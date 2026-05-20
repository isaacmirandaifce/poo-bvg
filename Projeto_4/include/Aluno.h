#ifndef ALUNO_H
#define ALUNO_H

#include <string>

class Aluno {
private:
    std::string nome;
    std::string matricula;
    std::string curso;

public:
    // Construtor padrão
    Aluno();

    // Construtor parametrizado
    Aluno(std::string nome, std::string matricula, std::string curso);

    // Getters
    std::string getNome() const;
    std::string getMatricula() const;
    std::string getCurso() const;

    // Exibe as informações básicas do aluno
    void exibirInformacoes() const;
};

#endif // ALUNO_H
