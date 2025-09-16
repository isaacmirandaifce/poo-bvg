#include "Aluno.h"
#include <stdexcept> // Para std::invalid_argument e std::stoi

Aluno::Aluno(int matricula, const std::string& nome)
    : matricula(matricula), nome(nome) {}

std::string Aluno::to_csv() const {
    return std::to_string(matricula) + "," + nome;
}

Aluno Aluno::from_csv(const std::string& csv_line) {
    std::stringstream ss(csv_line);
    std::string item;
    std::vector<std::string> tokens;

    while (std::getline(ss, item, ',')) {
        tokens.push_back(item);
    }

    if (tokens.size() != 2) {
        throw std::invalid_argument("Formato CSV inválido para Aluno.");
    }

    try {
        int matricula = std::stoi(tokens[0]);
        std::string nome = tokens[1];
        return Aluno(matricula, nome);
    } catch (const std::invalid_argument& e) {
        // Erro na conversão de string para int
        throw std::invalid_argument("Erro ao converter matrícula para número.");
    }
}