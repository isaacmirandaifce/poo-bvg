#ifndef DISCIPLINA_H
#define DISCIPLINA_H


#include <string>


class Disciplina {
public:
int id;
std::string nome;
int cargaHoraria;


Disciplina();
Disciplina(int id, const std::string &nome, int ch);


std::string toCSV() const; // id;nome;carga
static Disciplina fromCSV(const std::string &line);
};


#endif // DISCIPLINA_H