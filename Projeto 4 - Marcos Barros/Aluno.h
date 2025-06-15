#ifndef ALUNO_H
#define ALUNO_H

#include <string>
using namespace std;

class Aluno{
  
  private: 
    string nome;  
    matricula;    
    curso;
 
  public:
    aluno();
    aluno(string n, string m, string c);

    void exibirinformacoes() const;
};

#endif
