#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include <iostream>

class Disciplina {
private:
    int codigo;
    std::string nome;
    int cargaHoraria;
    int creditos;

public:
    Disciplina() : codigo(0), cargaHoraria(0), creditos(0) {}
    Disciplina(int codigo, const std::string& nome, int cargaHoraria, int creditos)
        : codigo(codigo), nome(nome), cargaHoraria(cargaHoraria), creditos(creditos) {}

    // Getters
    int getCodigo() const { return codigo; }
    std::string getNome() const { return nome; }
    int getCargaHoraria() const { return cargaHoraria; }
    int getCreditos() const { return creditos; }

    // Setters
    void setCodigo(int codigo) { this->codigo = codigo; }
    void setNome(const std::string& nome) { this->nome = nome; }
    void setCargaHoraria(int cargaHoraria) { this->cargaHoraria = cargaHoraria; }
    void setCreditos(int creditos) { this->creditos = creditos; }

    void exibir() const {
        std::cout << "Código: " << codigo << ", Nome: " << nome
                  << ", Carga Horária: " << cargaHoraria
                  << ", Créditos: " << creditos << std::endl;
    }
};

#endif
