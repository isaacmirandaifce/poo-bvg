#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <iostream>

class Aluno {
private:
    std::string nome;
    std::string matricula;
    std::string curso;

public:
    // Constructors
    Aluno();
    Aluno(const std::string& nome, const std::string& matricula, const std::string& curso);
    
    // Destructor
    ~Aluno();
    
    // Getters
    std::string getNome() const;
    std::string getMatricula() const;
    std::string getCurso() const;
    
    // Setters
    void setNome(const std::string& nome);
    void setMatricula(const std::string& matricula);
    void setCurso(const std::string& curso);
    
    // Métodos principais
    void exibirInformacoes() const;
};

#endif // ALUNO_H