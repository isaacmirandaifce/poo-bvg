#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <vector>

class Aluno : public virtual Usuario {
protected:
    std::string matricula;
    std::string curso;
    std::vector<std::string> disciplinas;

public:
    Aluno(std::string nome, std::string email, std::string matricula, std::string curso);

    void adicionarDisciplina(const std::string& disciplina);

    void gerarRelatorio() const override;

    // Sobrecarga de método
    void gerarRelatorio(bool incluirNotas) const;
};

#endif
