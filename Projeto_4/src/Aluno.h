#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>
#include "Disciplina.h"

class Aluno {
private:
    std::string nome;
    std::string matricula;
    std::string curso;

public:
    // Construtores
    Aluno();
    Aluno(const std::string& nome, const std::string& matricula, const std::string& curso);

    // Métodos
    void exibirInformacoes() const;

    // Getters
    const std::string& getNome() const;
    const std::string& getMatricula() const;
    const std::string& getCurso() const;

    // Setters
    void setNome(const std::string& nome);
    void setMatricula(const std::string& matricula);
    void setCurso(const std::string& curso);
};

#endif // ALUNO_H
