#ifndef ALUNO_H
#define ALUNO_H

#include "usuario.h"
#include <vector>

class aluno : virtual public usuario {
protected:
    std::string matricula;
    std::string curso;
    std::vector<std::string> disciplinas;

public:
    aluno();
    aluno(std::string nome, std::string email, std::string matricula, std::string curso);

    void adicionarDisciplina(std::string disciplina);
    void gerarRelatorio() const override;
    void gerarRelatorio(bool mostrarNotas) const;
};

#endif