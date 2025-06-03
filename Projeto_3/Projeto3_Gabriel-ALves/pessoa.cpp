#include "pessoa.h"
#include <iostream> // Para std::cout, std::endl 

// Utiliza o namespace std para simplificar a escrita do código 
using namespace std;

// Construtor padrão 
Pessoa::Pessoa() {
    this->nome = "Nao informado"; // Uso do ponteiro this 
    this->telefone = "Nao informado"; // Uso do ponteiro this 
    // cout << "Objeto Pessoa (padrão) criado." << endl; // Mensagem opcional
}

// Construtor parametrizado 
Pessoa::Pessoa(std::string nome, std::string telefone) {
    this->nome = nome; // Inicializa nome com valor fornecido, usando this 
    this->telefone = telefone; // Inicializa telefone com valor fornecido, usando this 
    // cout << "Objeto Pessoa '" << this->nome << "' criado via construtor parametrizado." << endl; // Mensagem opcional
}

// Destrutor 
// Exibe uma mensagem indicando a destruição do objeto 
Pessoa::~Pessoa() {
    cout << "Destruindo objeto Pessoa: " << this->nome << endl; // Uso do ponteiro this 
}

// Método para imprimir o nome da pessoa 
void Pessoa::imprimirNome() {
    // Utiliza o ponteiro this para demonstrar boas práticas 
    cout << "Nome: " << this->nome << endl;
}

// Método para imprimir o telefone da pessoa 
void Pessoa::imprimirTelefone() {
    // Utiliza o ponteiro this para demonstrar boas práticas 
    cout << "Telefone: " << this->telefone << endl;
}