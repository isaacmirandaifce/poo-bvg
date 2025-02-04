#include "../include/aluno.h"



// Construtor
Aluno::Aluno(std::string nome, std::string matricula, std::string curso)
    : nome(nome), matricula(matricula), curso(curso) {}

// Destruidor
Aluno::~Aluno() {
    // Aqui você pode colocar a implementação do destruidor, se necessário
}

// Método para exibir informações
void Aluno::exibirInformacoes() const {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Matricula: " << matricula << std::endl;
    std::cout << "Curso: " << curso << std::endl;
}