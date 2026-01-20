#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <vector>

class Aluno : public virtual Usuario {
protected:
    std::string matricula;
    std::string curso;
    std::vector<std::string> disciplinasCursadas;

public:
    Aluno();
    Aluno(const std::string& nome,
          const std::string& email,
          const std::string& matricula,
          const std::string& curso,
          const std::vector<std::string>& disciplinasCursadas);

    void gerarRelatorio() const override; //Sobescrita: Acontece quando as classes filhas implementam o mesmo método da base

    // Sobrecarga: exibe detalhes com ou sem notas
    void exibirDetalhes() const;
    void exibirDetalhes(const std::vector<float>& notas) const;

    std::string getMatricula() const;
    std::string getCurso() const;
};

#endif
