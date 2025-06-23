#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"
#include <vector>

class Professor : public virtual Usuario {
protected:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;
public:
    Professor();
    Professor(const std::string& nome, const std::string& email, const std::string& area);

    void adicionarDisciplina(const std::string& disciplina);

    void gerarRelatorio() const override; // sobrescrita
};

#endif