#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <iostream>
#include <string>

class Professor {
private:
    std::string nome;
    std::string email;
    std::string areaDeAtuacao;

public:
    Professor(std::string nome, std::string email, std::string areaDeAtuacao)
        : nome(nome), email(email), areaDeAtuacao(areaDeAtuacao) {}

    /* Método para exibir as informações do professor */
    void exibirInformacoes() const {
        std::cout << "Professor: " << nome << std::endl;
        std::cout << "Email: " << email << std::endl;
        std::cout << "Área de Atuação: " << areaDeAtuacao << std::endl;
    }
};

#endif // PROFESSOR_H
