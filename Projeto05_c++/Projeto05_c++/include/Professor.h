#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"
#include <vector>
#include <string>

class Professor : public Usuario {
private:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    // Construtores
    Professor();
    Professor(const std::string& nome, const std::string& email, const std::string& areaDeAtuacao);

    // Métodos
    void gerarRelatorio() const override;
    void adicionarDisciplina(const std::string& disciplina);
};

#endif // PROFESSOR_H
