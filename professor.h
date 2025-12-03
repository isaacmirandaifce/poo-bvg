#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "usuario.h"
#include <vector>

class Professor : virtual public Usuario {
protected:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    Professor();
    Professor(std::string nome, std::string email, std::string area);

    void adicionarDisciplinaMinistrada(std::string d);

    // SOBRESCRITA
    void gerarRelatorio() const override;
};

#endif
