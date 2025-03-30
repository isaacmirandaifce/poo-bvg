#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <iostream>

class Aluno {
private:
    std::string nome;
    int idade;

public:
    // Construtor padrão
    Aluno() : nome(""), idade(0) {}

    // Construtor parametrizado
    Aluno(const std::string& nome, int idade) : nome(nome), idade(idade) {}

    // Getters
    std::string getNome() const { return nome; }
    int getIdade() const { return idade; }

    // Setters
    void setNome(const std::string& nome) { this->nome = nome; }
    void setIdade(int idade) { this->idade = idade; }

    // Método para exibir dados do aluno
    void exibirDados() const {
        std::cout << "Nome: " << nome << ", Idade: " << idade << std::endl;
    }

    // Sobrecarga de operador para comparação (opcional)
    bool operator==(const Aluno& outro) const {
        return nome == outro.nome && idade == outro.idade;
    }
};

#endif // ALUNO_H