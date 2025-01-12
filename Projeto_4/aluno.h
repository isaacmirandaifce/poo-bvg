//proteje de inclusões multiplas
#ifndef ALUNO_H
#define ALUNO_H

#include <string>

//definindo a classe aluno
class Aluno {
private:
    std::string nome;
    std::string matricula;
    std::string curso;

public:
    //construtor padrão
    Aluno();
    Aluno(std::string nome, std::string matricula, std::string curso);
    void exibirInformacoes() const;

    //metodos pra acessar atributos privados
    std::string getNome() const;
    std::string getMatricula() const;
    std::string getCurso() const;
};

#endif
