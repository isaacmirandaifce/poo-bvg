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
    Professor(const std::string& nome,
              const std::string& email,
              const std::string& areaDeAtuacao,
              const std::vector<std::string>& disciplinasMinistradas);

    void gerarRelatorio() const override;

    std::string getAreaDeAtuacao() const;
};

#endif
