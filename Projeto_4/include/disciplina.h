#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

class Disciplina {
private:
    std::string nome;
    int cargaHoraria;
    float nota;

public:
    Disciplina(std::string nome, int cargaHoraria, float nota);
    ~Disciplina();  // Apenas a declaração do destruidor
    
    // Método para exibir informações da disciplina
    void exibirInformacoes() const;

    void setNota(float nota);
    float getNota() const;

    // Declarando a função amiga
    friend bool verificarAprovacao(const Disciplina& disciplina);
};


#endif // DISCIPLINA_H
