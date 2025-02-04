#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"
#include <vector>

class Professor : public Usuario {
private:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    Professor();
    Professor(const std::string& nome, const std::string& email, const std::string& areaDeAtuacao, const std::vector<std::string>& disciplinas);

    void gerarRelatorio() const override;
};

#endif // PROFESSOR_H
