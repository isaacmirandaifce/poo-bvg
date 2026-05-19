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
    Professor(std::string n, std::string e, std::string t, std::string area, std::vector<std::string> disc);
    virtual ~Professor() {}

    void gerarRelatorio() override;
};

#endif