#ifndef ALUNO_H
#define ALUNO_H

#include <string>
using namespace std;

class Aluno {
private:
    string nome;
    string matricula;
    string curso;

public:
    Aluno(); // Construtor padrão
    Aluno(string n, string m, string c); // Construtor parametrizado
    void exibirInformacoes();
};

#endif
