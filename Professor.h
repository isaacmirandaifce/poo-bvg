#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <iostream>
#include <vector>

class Professor {
private:
    std::string nome;
    std::vector<std::string> disciplinas;

public:
    Professor(std::string nome) : nome(nome) {}

    void adicionarDisciplina(const std::string& disciplina) {
        disciplinas.push_back(disciplina);
    }

    const std::vector<std::string>& getDisciplinas() const {
        return disciplinas;
    }

    std::string getNome() const { return nome; }

    void imprimir() const {
        std::cout << "Professor: " << nome << ", Disciplinas: ";
        for (const auto& d : disciplinas) {
            std::cout << d << " ";
        }
        std::cout << std::endl;
    }
};

#endif // PROFESSOR_H