#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include "Disciplina.h"
#include <vector>

class Aluno : public virtual Usuario {
protected:
    string matricula;
    string curso;
    vector<Disciplina> disciplinas;

public:
    Aluno();
    Aluno(string n, string e, string m, string c);

    void adicionarDisciplina(const Disciplina& d);
    void gerarRelatorio() const override;

    // Sobrecarga
    void gerarRelatorio(bool comNota) const;
};

#endif
