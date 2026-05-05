#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"
#include <vector>
#include <string>

// Herança virtual utilizada para composição do Monitor
class Professor : virtual public Usuario {
protected:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    Professor(std::string nome, std::string email, std::string area, std::vector<std::string> disciplinas);

    void gerarRelatorio() override;
};

#endif
