#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include "disciplina.h"
#include <vector>

class Aluno : virtual public Usuario {
protected:
    std::string matricula;
    std::string curso;
    std::vector<Disciplina> disciplinas;

public:
    Aluno();
    Aluno(std::string nome, std::string email, std::string matricula, std::string curso);

    void adicionarDisciplina(const Disciplina& d);

    void gerarRelatorio() const override;

    // Sobrecarga
    void exibirInformacoes() const;
    void exibirInformacoes(bool comNotas) const;
};

#endif
