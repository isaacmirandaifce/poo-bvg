#include "Professor.h"
#include "Exceptions.h"
#include <sstream>


Professor::Professor(): id(0), nome(""), departamento("") {}
Professor::Professor(int id, const std::string &nome, const std::string &dept): id(id), nome(nome), departamento(dept) {}


std::string Professor::toCSV() const {
std::ostringstream oss;
oss << id << ";" << nome << ";" << departamento;
return oss.str();
}

Professor Professor::fromCSV(const std::string &line) {
std::istringstream iss(line);
std::string token;
int id;
std::string nome, dept;


try {
if (!std::getline(iss, token, ';')) throw ConversaoDadosException("campo id ausente");
id = std::stoi(token);
if (!std::getline(iss, nome, ';')) throw ConversaoDadosException("campo nome ausente");
if (!std::getline(iss, dept)) throw ConversaoDadosException("campo departamento ausente");
} catch (const std::invalid_argument &e) {
throw ConversaoDadosException("id invalido");
} catch (const std::out_of_range &e) {
throw ConversaoDadosException("id fora de alcance");
}


return Professor(id, nome, dept);
}