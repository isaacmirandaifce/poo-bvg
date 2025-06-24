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
    Aluno();
    Aluno(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso);

    void adicionarDisciplina(const std::string& disciplina);
    void gerarRelatorio() const override;

    void gerarRelatorio(bool mostrarNotas) const; // Sobrecarga
};

#endif