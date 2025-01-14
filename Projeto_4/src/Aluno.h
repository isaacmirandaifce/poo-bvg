#ifndef ALUNO_H
#define ALUNO_H

#include <string>

//Cria a classe aluno com nome, matricula e curso
class Aluno {
private:
    //Encapsula os atributos
    std::string nome;
    std::string matricula;
    std::string curso;

public:
    // Construtores
    Aluno();
    Aluno(const std::string& nome, const std::string& matricula, const std::string& curso);

    // Método exibirInformacoes
    void exibirInformacoes() const;

    // Getters
    std::string getNome() const;
    std::string getMatricula() const;
    std::string getCurso() const;
};

#endif // ALUNO_H
