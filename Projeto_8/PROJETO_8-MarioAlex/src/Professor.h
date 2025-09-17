#ifndef PROFESSOR_H
#define PROFESSOR_H


#include <string>


class Professor {
public:
int id;
std::string nome;
std::string departamento;


Professor();
Professor(int id, const std::string &nome, const std::string &dept);


std::string toCSV() const; // id;nome;departamento
static Professor fromCSV(const std::string &line);
};


#endif // PROFESSOR_H