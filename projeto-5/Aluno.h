#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <string>
#include <vector>

class Aluno : public virtual Usuario
{
    protected:
        std::string matricula;
        std::string curso;
        std::vector<std::string> disciplinasCursadas;

    public:
        Aluno(std::string nome, std::string email, std::string matricula, std::string curso);

        // Sobrescrita do método da classe base
        void gerarRelatorio() override;

        // Sobrecarga do método gerarRelatorio
        void gerarRelatorio(bool comNotas);

        void adicionarDisciplina(const std::string& disciplina);
};

#endif
