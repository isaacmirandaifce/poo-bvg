#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"
#include <vector>

class Professor : public virtual Usuario { // Herança virtual de Usuario
private:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    Professor(const std::string& nome, const std::string& email, const std::string& areaDeAtuacao);
    void adicionarDisciplina(const std::string& disciplina);
    void gerarRelatorio() const override;
};

#endif // PROFESSOR_H
