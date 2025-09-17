#ifndef ALUNO_H
#define ALUNO_H


#include <string>


class Aluno {
public:
int id;
std::string nome;
std::string matricula;


Aluno();
Aluno(int id, const std::string &nome, const std::string &matricula);


std::string toCSV() const; // id;nome;matricula
static Aluno fromCSV(const std::string &line); // lança ConversaoDadosException em erro
};


#endif // ALUNO_H