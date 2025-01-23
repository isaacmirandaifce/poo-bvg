#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

// Declara que a função amiga será usada
class Disciplina;

class Aluno;

// Classe disciplina com nome, carga horaria e nota
class Disciplina {
private:
    // Encapsula os atributos
    std::string nome;
    int cargaHoraria;
    float nota;

public:
    // Construtores
    Disciplina();
    Disciplina(const std::string& nome, int cargaHoraria, float nota = 0.0);

    // Métodos
    void setNota(float nota);
    float getNota() const;

    // Getters adicionais para obter nome e carga horaria
    std::string getNome() const;
    int getCargaHoraria() const;

    // Função amiga para verificar aprovação
    friend bool verificarAprovacao(const Disciplina& disciplina);
};

// Função amiga que verifica se o aluno foi aprovado ou não
bool verificarAprovacao(const Disciplina& disciplina);

#endif // DISCIPLINA_H
