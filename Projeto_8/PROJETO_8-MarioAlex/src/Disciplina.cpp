#include "Disciplina.h"
#include "Exceptions.h"
#include <sstream>


Disciplina::Disciplina(): id(0), nome(""), cargaHoraria(0) {}
Disciplina::Disciplina(int id, const std::string &nome, int ch): id(id), nome(nome), cargaHoraria(ch) {}


std::string Disciplina::toCSV() const {
std::ostringstream oss;
oss << id << ";" << nome << ";" << cargaHoraria;
return oss.str();
}

Disciplina Disciplina::fromCSV(const std::string &line) {
std::istringstream iss(line);
std::string token;
int id; int ch;
std::string nome;


try {
if (!std::getline(iss, token, ';')) throw ConversaoDadosException("campo id ausente");
id = std::stoi(token);
if (!std::getline(iss, nome, ';')) throw ConversaoDadosException("campo nome ausente");
if (!std::getline(iss, token)) throw ConversaoDadosException("campo carga ausente");
ch = std::stoi(token);
} catch (const std::invalid_argument &e) {
throw ConversaoDadosException("numero invalido");
} catch (const std::out_of_range &e) {
throw ConversaoDadosException("numero fora de alcance");
}


return Disciplina(id, nome, ch);
}