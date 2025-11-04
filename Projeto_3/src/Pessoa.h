#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

using namespace std;

// Classe Pessoa
class Pessoa {
private:
    // Atributos privados: armazenam dados da pessoa.
    string nome = "";
    string telefone = "";
public:
    // Construtor padrão
    // Cria um objeto Pessoa com nome e telefone vazios.
    Pessoa();

    // Construtor parametrizado
    // Recebe nome e telefone (por valor) e inicializa o objeto.
    Pessoa(string nome, string telefone);

    // Destrutor
    // Chamado quando o objeto é destruído; usado para liberar recursos.
    ~Pessoa();

    // Método para imprimir o nome da pessoa.
    void imprimirNome() const;

    // Método para imprimir o telefone da pessoa.
    void imprimirTelefone() const;
};

#endif // PESSOA_H