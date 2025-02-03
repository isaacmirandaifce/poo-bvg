#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <iostream>

class Aluno {
private:
    std::string nome;
    double media;

public:
    Aluno(std::string nome, double media) : nome(nome), media(media) {}

    /* Getter para a média */
    double getMedia() const {
        return media;
    }

    /* Getter para o nome */
    std::string getNome() const {
        return nome;
    }

    /* Método para exibir as informações do aluno */
    void exibirInformacoes() const {
        std::cout << "Aluno: " << nome << ", Média: " << media << std::endl;
    }
};

#endif // ALUNO_H
