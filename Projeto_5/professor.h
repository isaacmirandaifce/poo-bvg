#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"
#include <vector>
#include <string>

class Professor : public virtual Usuario {
private:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    Professor();
    Professor(const std::string& nome, const std::string& email, const std::string& areaDeAtuacao);

    void adicionarDisciplina(const std::string& disciplina);
    void gerarRelatorio() const override;

    ~Professor() {}
};

#endif 
