#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"
#include <string>
#include <vector>

class Professor : public virtual Usuario
{
    protected:
        std::string areaDeAtuacao;
        std::vector<std::string> disciplinasMinistradas;

    public:
        Professor(std::string nome, std::string email, std::string areaDeAtuacao);
        void adicionarDisciplina(const std::string& disciplina);
        void gerarRelatorio() override;
};

#endif
