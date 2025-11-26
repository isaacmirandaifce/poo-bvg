#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"
#include <vector>

class Professor : public Usuario {
private:
    string areaDeAtuacao;
    vector<string> disciplinasMinistradas;

public:
    Professor();
    Professor(const string &nome, const string &email, const string &area);
    ~Professor();

    void adicionarDisciplina(const string &disciplina);
    void gerarRelatorio() const override;

    const vector<string>& getDisciplinasMinistradas() const;
    string getArea() const;
};

#endif // PROFESSOR_H