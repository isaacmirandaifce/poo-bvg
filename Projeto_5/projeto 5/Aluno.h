#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"

// Herança virtual para permitir herança múltipla na classe Monitor
class Aluno : virtual public Usuario {
protected:
    std::string matricula;
    std::string curso;

public:
    Aluno(std::string nome, std::string email, std::string matricula, std::string curso);

    void gerarRelatorio() override;

    // Sobrecarga de métodos
    void exibirDetalhes();
    void exibirDetalhes(bool comNotas);
};

#endif
