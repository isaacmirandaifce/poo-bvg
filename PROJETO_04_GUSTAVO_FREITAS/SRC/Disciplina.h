#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

class Disciplina {
private:
    std::string nome;
    int cargaHoraria;
    float nota;

public:
    // Construtores
    Disciplina();
    Disciplina(std::string nome, int cargaHoraria, float nota = 0.0f);
    
    // Métodos para notas
    void setNota(float nota);
    float getNota() const;
    
    // Getters
    std::string getNome() const;
    int getCargaHoraria() const;
    
    // Função amiga para verificar aprovação
    friend bool verificarAprovacao(const Disciplina& disciplina);
};

// Declaração da função amiga
bool verificarAprovacao(const Disciplina& disciplina);

#endif // DISCIPLINA_H