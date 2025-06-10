#ifndef ALUNO_H
#define ALUNO_H

#include <string>

class Aluno {
private:
    std::string nome;
    std::string matricula;
    std::string curso;

public:
    // Construtor padrão
    Aluno();
    // Construtor parametrizado
    Aluno(std::string nome, std::string matricula, std::string curso);

    // Método para exibir informações básicas do aluno 
    void exibirInformacoes() const;

    // Método para obter o nome do aluno
    std::string getNome() const;
};

#endif // ALUNO_H