#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

// Forward declaration da classe Aluno para uso na função amiga
class Aluno; 

class Disciplina {
private:
    std::string nome;
    int cargaHoraria;
    float nota;

public:
    // Construtor padrão e parametrizado 
    Disciplina();
    Disciplina(std::string nome, int cargaHoraria);

    // Métodos para configurar e obter as notas 
    void setNota(float n);
    float getNota() const;
    std::string getNome() const;

    // Declaração da função amiga 
    friend void verificarStatusAprovacao(const Aluno& aluno, const Disciplina& disciplina);
};

#endif // DISCIPLINA_H