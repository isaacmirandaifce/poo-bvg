#include <iostream>
#include <string>
#include "contato.h"

void Contato::setTelefone(std::string telefone)
{

    this->telefone = telefone;
};

void Contato::setNome(std::string nome)
{

    this->nome = nome;
};

Contato::Contato()
{
    std::cout << "Contato criado." << '\n';
};

Contato::~Contato()
{

    std::cout << "O contato de nome '" << nome << "' foi apagado com sucesso." << '\n';
};

void Contato::imprimirNome()
{

    std::cout << "O nome deste contato é: " << this->nome << '\n';
};

void Contato::imprimirTelefone()
{

    std::cout << "O número deste contato é: " << this->telefone << '\n';
};

Contato AdicionarContatos(std::string nome, std::string telefone)
{
    Contato novo;
    novo.setNome(nome);
    novo.setTelefone(telefone);
    return novo;
}
