#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"
#include <vector>
using namespace std;

class Professor : public Usuario {
private:
    string areaDeAtuacao;
    vector<string> disciplinasMinistradas;

public:
    Professor(const string& nome, const string& email, const string& areaDeAtuacao, const vector<string>& disciplinas);

    // Sobrescrevendo gerarRelatorio
    void gerarRelatorio() const override;
};

#endif
