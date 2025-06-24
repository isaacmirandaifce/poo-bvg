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
    Aluno(); 
    Aluno(const std::string& nome, const std::string& matricula, const std::string& curso);  // Construtor com parâmetros

    void exibirInformacoes() const;
};

#endif 
