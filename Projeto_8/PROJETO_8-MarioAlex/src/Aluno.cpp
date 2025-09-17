#include "Aluno.h"
#include "Exceptions.h"
#include <sstream>


Aluno::Aluno(): id(0), nome(""), matricula("") {}
Aluno::Aluno(int id, const std::string &nome, const std::string &matricula): id(id), nome(nome), matricula(matricula) {}


std::string Aluno::toCSV() const {
std::ostringstream oss;
oss << id << ";" << nome << ";" << matricula;
return oss.str();
}

Aluno Aluno::fromCSV(const std::string &line) {
std::istringstream iss(line);
std::string token;
int id;
std::string nome, matricula;


// formato esperado: id;nome;matricula
try {
if (!std::getline(iss, token, ';')) throw ConversaoDadosException("campo id ausente");
id = std::stoi(token);
if (!std::getline(iss, nome, ';')) throw ConversaoDadosException("campo nome ausente");
if (!std::getline(iss, matricula)) throw ConversaoDadosException("campo matricula ausente");
} catch (const std::invalid_argument &e) {
throw ConversaoDadosException("id invalido");
} catch (const std::out_of_range &e) {
throw ConversaoDadosException("id fora de alcance");
}


return Aluno(id, nome, matricula);
}