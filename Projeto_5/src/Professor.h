#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"
#include <vector>

class Professor : virtual public Usuario {
protected:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    Professor();
    Professor(std::string nome, std::string email, std::string area);

    void adicionarDisciplina(const std::string& disciplina);
    void gerarRelatorio() const override;
};

#endif
