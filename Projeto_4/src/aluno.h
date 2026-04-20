#ifndef ALUNO_H
#define ALUNO_H

#include <string>

class Aluno {
private:
    std:: string nome;
    std:: string matricula;
    std:: string curso;
public:
Aluno(); //esse é o construtor padrão
Aluno(std::string nome, std ::string matricula, std::string curso); //construtor parametrizado

void exibirInformacoes(); //função para ser chamada em aluno.cpp
};

#endif