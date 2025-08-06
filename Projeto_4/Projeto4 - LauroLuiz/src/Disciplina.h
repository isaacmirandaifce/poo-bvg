#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include <iostream>

class Disciplina {
private:
    std::string nome;
    int cargaHoraria;
    float nota;

public:
    // Constructors
    Disciplina();
    Disciplina(const std::string& nome, int cargaHoraria);
    Disciplina(const std::string& nome, int cargaHoraria, float nota);
    
    // Destructor
    ~Disciplina();
    
    // Getters
    std::string getNome() const;
    int getCargaHoraria() const;
    float getNota() const;
    
    // Setters
    void setNome(const std::string& nome);
    void setCargaHoraria(int cargaHoraria);
    void setNota(float nota);
    
    // Método para exibir informações da disciplina
    void exibirInformacoes() const;
    
    // Função amiga para verificar aprovação
    friend bool verificarAprovacao(const Disciplina& disciplina);
    
    // Função amiga para validar critérios de aprovação
    friend bool validarCriteriosAprovacao(const Disciplina& disciplina, float notaMinima);
};

// Declaração das funções amigas
bool verificarAprovacao(const Disciplina& disciplina);
bool validarCriteriosAprovacao(const Disciplina& disciplina, float notaMinima = 6.0f);

#endif // DISCIPLINA_H