#ifndef ALUNO_H
#define ALUNO_H

#include <string>

//declaração da classe aluno
class Aluno {
private:

    //atributos privados pra armazenar as informações do aluno
    std::string nome;
    std::string id;
    std::string curso;

public:
    
    //construtor da classe aluno
    Aluno(std::string nome, std::string id, std::string curso);
    
    //metodo publico para exibir as informações do aluno
    void exibirInformacoes() const;

    //metodo de acesso para obter os valores dos atributos
    std::string getNome() const { return nome; }
    std::string getId() const { return id; }
    std::string getCurso() const { return curso; }
};

#endif
