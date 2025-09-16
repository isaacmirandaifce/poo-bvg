#include "Professor.h"
#include <vector>
#include <sstream>
#include <stdexcept>

Professor::Professor(int id, const std::string& nome) : id(id), nome(nome) {}

std::string Professor::to_csv() const {
    return std::to_string(id) + "," + nome;
}

Professor Professor::from_csv(const std::string& csv_line) {
    std::stringstream ss(csv_line);
    std::string item;
    std::vector<std::string> tokens;
    while (std::getline(ss, item, ',')) {
        tokens.push_back(item);
    }
    if (tokens.size() != 2) {
        throw std::invalid_argument("Formato CSV inválido para Professor.");
    }
    try {
        return Professor(std::stoi(tokens[0]), tokens[1]);
    } catch (const std::invalid_argument& e) {
        throw std::invalid_argument("Erro ao converter ID do professor para número.");
    }
}