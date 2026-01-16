#ifndef PESSOA_H
#define PESSOA_H

// Biblioteca que permite o uso da classe std::string (strings em C++)
#include <string>

// Biblioteca padrão para entrada e saída de dados (std::cout, std::endl)
#include <iostream>

// Declaração da classe Pessoa
class Pessoa {
private:
    // Atributos privados (aplicando encapsulamento)
    std::string nome;       // Armazena o nome da pessoa
    std::string telefone;   // Armazena o telefone da pessoa

public:
    // Construtor padrão (sem parâmetros)
    Pessoa();

    // Construtor com parâmetros (inicializa nome e telefone)
    Pessoa(std::string nome, std::string telefone);

    // Destrutor (executado automaticamente ao destruir o objeto)
    ~Pessoa();
    
    // Métodos que exibem os dados da pessoa
    void imprimirNome();        // Mostra o nome no terminal
    void imprimirTelefone();    // Mostra o telefone no terminal
    
    // Métodos modificadores (setters) — alteram os atributos
    void setNome(std::string nome);
    void setTelefone(std::string telefone);
    
    // Métodos de acesso (getters) — retornam os valores dos atributos
    std::string getNome() const;
    std::string getTelefone() const;
};

// Fim da diretiva de proteção contra múltiplas inclusões
#endif // PESSOA_H