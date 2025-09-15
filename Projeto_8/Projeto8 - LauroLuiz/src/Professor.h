#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <iostream>

class Professor {
private:
    int id;
    std::string nome;
    std::string disciplina;
    std::string departamento;

public:
    Professor() : id(0) {}
    Professor(int id, const std::string& nome, const std::string& disciplina,
              const std::string& departamento)
        : id(id), nome(nome), disciplina(disciplina), departamento(departamento) {}

    // Getters
    int getId() const { return id; }
    std::string getNome() const { return nome; }
    std::string getDisciplina() const { return disciplina; }
    std::string getDepartamento() const { return departamento; }

    // Setters
    void setId(int id) { this->id = id; }
    void setNome(const std::string& nome) { this->nome = nome; }
    void setDisciplina(const std::string& disciplina) { this->disciplina = disciplina; }
    void setDepartamento(const std::string& departamento) { this->departamento = departamento; }

    void exibir() const {
        std::cout << "ID: " << id << ", Nome: " << nome
                  << ", Disciplina: " << disciplina
                  << ", Departamento: " << departamento << std::endl;
    }
};

#endif
