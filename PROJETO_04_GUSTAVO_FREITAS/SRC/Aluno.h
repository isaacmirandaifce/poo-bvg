#ifndef ALUNO_H
#define ALUNO_H

#include <string>

class Aluno {
private:
    std::string nome;
    std::string matricula;
    std::string curso;

public:
    // Construtores
    Aluno();
    Aluno(std::string nome, std::string matricula, std::string curso);
    
    // Métodos para exibir informações
    void exibirInformacoes() const;
    
    // Getters
    std::string getNome() const;
    std::string getMatricula() const;
    std::string getCurso() const;
    
    // Setters
    void setNome(std::string nome);
    void setMatricula(std::string matricula);
    void setCurso(std::string curso);
};

#endif // ALUNO_H