#ifndef PESSOA_H
#define PESSOA_H

#include <string>
//Criando a classe pessoa com atributos nome e telfone
class Pessoa {
private:
    std::string nome;
    std::string telefone;

public:
    //Construtor
    Pessoa(const std::string& nome, const std::string& telefone);

    //Destrutor
    ~Pessoa();

    //Getters
    std::string getNome() const;
    std::string getTelefone() const;

    //Métodos
    void imprimirNome() const;
    void imprimirTelefone() const;
};

#endif