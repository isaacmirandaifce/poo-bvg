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
    Professor(const std::string& nome, const std::string& email, const std::string& areaDeAtuacao);

    void adicionarDisciplina(const std::string& disciplina);
    virtual void gerarRelatorio() const override;
};

#endif // PROFESSOR_H
