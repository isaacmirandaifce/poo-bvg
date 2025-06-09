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
    Aluno();  // construtor padrão
    Aluno(string n, string m, string c); // construtor parametrizado

    void exibirInformacoes() const;
};

#endif // ALUNO_H