#ifndef PESSOA_H //ver se a classe já foi definida, usado para  previnir problema com a redefinição da classe
#define PESSOA_H

#include <string>
#include <iostream>

class Pessoa {
private:
    std::string nome;
    std::string telefone;

public:
    // Construtor padrão
    Pessoa();

    // Construtor parametrizado
    Pessoa(
        const std::string& nome, 
        const std::string& telefone
        );

    // Destrutor
    ~Pessoa();

    // Métodos de impressão
    void imprimirNome() const;
    void imprimirTelefone() const;
};

#endif //marca o fim da definição da classe q deve ser incluida apenas uma vez
