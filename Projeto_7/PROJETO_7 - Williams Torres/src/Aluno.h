#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <iostream>

class Aluno {
private:
    std::string nome;
    double media;
    std::string disciplina;

public:
    Aluno(const std::string& nome, double media, const std::string& disciplina) : nome(nome), media(media), disciplina(disciplina) {}

    std::string getNome() const { return nome; }
    double getMedia() const { return media; }
    std::string getDisciplina() const { return disciplina; }

    void imprimir() const {
        std::cout << "Aluno: " << nome << ", Média: " << media << ", Disciplina: " << disciplina << std::endl;
    }

    bool operator<(const Aluno& outro) const {
        return media < outro.media;
    }
};

#endif // ALUNO_H