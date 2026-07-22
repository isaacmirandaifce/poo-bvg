#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <vector>
#include "Usuario.h"

class Professor : virtual public Usuario {
protected:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    Professor();
    Professor(std::string nome, std::string email, std::string areaDeAtuacao);

    void adicionarDisciplinaMinistrada(const std::string& disciplina);

    // Sobrescrita: implementacao do relatorio geral herdado de Usuario
    void gerarRelatorio() const override;
};

#endif // PROFESSOR_H
