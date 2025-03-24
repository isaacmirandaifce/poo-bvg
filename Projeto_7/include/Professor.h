#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "Usuario.h"
#include "Relatorio.h"
#include <vector>

class Professor : public Usuario, public Relatorio {
protected:
    string areaAtuacao;
    vector<string> disciplinasMinistradas;
public:
    Professor(string n, string e, string a) : Usuario(n, e), areaAtuacao(a) {}
    void adicionarDisciplina(string disciplina);
    void gerarRelatorio() const override;
    const vector<string>& getDisciplinasMinistradas() const { return disciplinasMinistradas; }
};

#endif // PROFESSOR_H