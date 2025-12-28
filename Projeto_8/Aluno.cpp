#include "Aluno.h"
#include <sstream>
#include <stdexcept>

Aluno::Aluno() : id(0), nome("") {}

Aluno::Aluno(int id, const std::string& nome) : id(id), nome(nome) {}

int Aluno::getId() const {
    return id;
}

std::string Aluno::getNome() const {
    return nome;
}

std::string Aluno::toString() const {
    return std::to_string(id) + ";" + nome;
}

Aluno Aluno::fromString(const std::string& linha) {
    std::stringstream ss(linha);
    std::string idStr, nomeStr;

    if (!std::getline(ss, idStr, ';') || !std::getline(ss, nomeStr)) {
        throw std::invalid_argument("Falha na conversao");
    }

    return Aluno(std::stoi(idStr), nomeStr);
}
