#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "UsuarioAutenticavel.h"
#include <vector>

using namespace std;

class Professor : public UsuarioAutenticavel {
private:
    string areaDeAtuacao;
    vector<string> disciplinasMinistradas;

public:
    Professor();
    Professor(string nome, string email, string senha, string area);

    void disciplinasAdicionadas(string disciplina);
    bool autenticar(string senha) override;
    void gerarRelatorio() const override;
    bool ministraDisciplina(string nome) const;
};




#endif
