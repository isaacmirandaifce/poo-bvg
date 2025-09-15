#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <iostream>

class Aluno {
private:
    int id;
    std::string nome;
    std::string curso;
    double nota;

public:
    Aluno() : id(0), nota(0.0) {}
    Aluno(int id, const std::string& nome, const std::string& curso, double nota)
        : id(id), nome(nome), curso(curso), nota(nota) {}

    // Getters
    int getId() const { return id; }
    std::string getNome() const { return nome; }
    std::string getCurso() const { return curso; }
    double getNota() const { return nota; }

    // Setters
    void setId(int id) { this->id = id; }
    void setNome(const std::string& nome) { this->nome = nome; }
    void setCurso(const std::string& curso) { this->curso = curso; }
    void setNota(double nota) { this->nota = nota; }

    // Método para exibir dados do aluno
    void exibir() const {
        std::cout << "ID: " << id << ", Nome: " << nome
                  << ", Curso: " << curso << ", Nota: " << nota << std::endl;
    }
};

#endif
