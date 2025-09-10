#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "usuario.h"
#include <vector>

class professor : virtual public usuario {
protected:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    professor();
    professor(std::string nome, std::string email, std::string area);

    void adicionarDisciplina(std::string disciplina);
    void gerarRelatorio() const override;
};

#endif