// Inclui o cabeçalho da classe Pessoa, onde estão as declarações da classe e métodos
#include "Pessoa.h"

// Construtor padrão: inicializa nome e telefone com valores vazios
Pessoa::Pessoa() : nome(""), telefone("") {}

// Construtor com parâmetros: inicializa com valores informados
Pessoa::Pessoa(std::string nome, std::string telefone) 
    : nome(nome), telefone(telefone) {}

// Destrutor: executa automaticamente quando o objeto é destruído
Pessoa::~Pessoa() {
    std::cout << "Destruindo: " << nome << std::endl;
}

// Exibe o nome da pessoa
void Pessoa::imprimirNome() {
    std::cout << "Nome: " << nome << std::endl;
}

// Exibe o telefone da pessoa
void Pessoa::imprimirTelefone() {
    std::cout << "Telefone: " << telefone << std::endl;
}

// Define (altera) o nome da pessoa
void Pessoa::setNome(std::string nome) {
    this->nome = nome; // "this" referencia o objeto atual
}

// Define (altera) o telefone da pessoa
void Pessoa::setTelefone(std::string telefone) {
    this->telefone = telefone;
}

// Retorna o nome da pessoa
std::string Pessoa::getNome() const {
    return nome;
}

// Retorna o telefone da pessoa
std::string Pessoa::getTelefone() const {
    return telefone;
}