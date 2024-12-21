#include "Pessoa.H"

// Construtor padrão
Pessoa::Pessoa() : nome("Indefinido"), telefone("Indefinido") {
    std::cout << "Pessoa criado (padrão)" << std::endl;
}

// Construtor parametrizado
Pessoa::Pessoa(const std::string &nome, const std::string &telefone) 
    : nome(nome), telefone(telefone) {
    std::cout << "Pessoa criado com dados fornecidos" << std::endl;
}

// Destrutor
Pessoa::~Pessoa() {
    std::cout << "Pessoa destruida: " << this->nome << std::endl;
}

// Métodos de impressão
void Pessoa::imprimirNome() const {
    std::cout << "Nome: " << this->nome << std::endl;
}

void Pessoa::imprimirTelefone() const {
    std::cout << "Telefone: " << this->telefone << std::endl;
}
