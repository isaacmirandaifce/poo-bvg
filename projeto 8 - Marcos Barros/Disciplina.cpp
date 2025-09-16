#include "Disciplina.h"
#include <vector>
#include <sstream>
#include <stdexcept>

Disciplina::Disciplina(const std::string& codigo, const std::string& nome) : codigo(codigo), nome(nome) {}

std::string Disciplina::to_csv() const {
    return codigo + "," + nome;
}

Disciplina Disciplina::from_csv(const std::string& csv_line) {
    std::stringstream ss(csv_line);
    std::string item;
    std::vector<std::string> tokens;
    while (std::getline(ss, item, ',')) {
        tokens.push_back(item);
    }
    if (tokens.size() != 2) {
        throw std::invalid_argument("Formato CSV inválido para Disciplina.");
    }
    // Não há conversão de número aqui, então é mais simples
    return Disciplina(tokens[0], tokens[1]);
}