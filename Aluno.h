#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <iostream>
#include <vector>
#include "Disciplina.h"

class Aluno {
private:
    std::string nome;
    double media;
    int ano;
    std::vector<Disciplina> disciplinas;

public:
    Aluno(std::string nome, double media, int ano) : nome(nome), media(media), ano(ano) {}

    std::string getNome() const { return nome; }
    double getMedia() const { return media; }
    int getAno() const { return ano; }

    void adicionarDisciplina(const Disciplina& d) {
        disciplinas.push_back(d);
    }

    const std::vector<Disciplina>& getDisciplinas() const {
        return disciplinas;
    }

    void imprimir() const {
        std::cout << "Nome: " << nome << ", Média: " << media << ", Ano: " << ano << std::endl;
        for (const auto& d : disciplinas) {
            std::cout << "  - ";
            d.imprimir();
        }
    }
};

#endif 