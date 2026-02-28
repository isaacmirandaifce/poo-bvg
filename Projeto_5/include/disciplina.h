#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

class Disciplina {
private:
    std::string nome;
    int cargaHoraria;
    float nota;

public:
    // Construtor e destrutor
    Disciplina(std::string nome, int cargaHoraria, float nota);
    ~Disciplina();

    // Método para exibir informações
    void exibirInformacoes() const;

    // Setters e getters
    void setNota(float nota);
    float getNota() const;

    // Função amiga para verificar aprovação
    friend bool verificarAprovacao(const Disciplina& disciplina);
};

#endif // DISCIPLINA_H
