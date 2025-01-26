#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <vector>
#include <string>
using namespace std;

class Aluno : public Usuario {
private:
    string matricula;
    string curso;
    vector<string> disciplinas;

public:
    Aluno(const string& nome, const string& email, const string& matricula, const string& curso);

    // Sobrescrevendo gerarRelatorio (de Usuario)
    void gerarRelatorio() const override;

    // Sobrecarga para exibir informações detalhadas com notas
    void gerarRelatorio(const vector<float>& notas) const;
};

#endif

