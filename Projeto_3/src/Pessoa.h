#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

namespace app {

class Pessoa {
private:
    // Membros privados podem ser adicionados futuramente

public:
    std::string nome;
    std::string telefone;

    // Construtor padrão
    Pessoa();

    // Construtor parametrizado
    Pessoa(const std::string &nome, const std::string &telefone);

    // Destrutor
    ~Pessoa();

    // Métodos de impressão
    void imprimirNome() const;
    void imprimirTelefone() const;
};

}

#endif // PESSOA_H