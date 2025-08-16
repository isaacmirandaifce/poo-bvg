#ifndef ALUNO_H
#define ALUNO_H

#include "../Usuarios/Usuario.h"
#include <vector>

class Aluno : public virtual Usuario {
protected:
    string matricula;
    string curso;
    vector<string> disciplinas;

public:
    Aluno();
    Aluno(string nome, string email, string tipo, string matricula, string curso, vector<string> disciplinas);
    void gerarRelatorio() override;
    void gerarRelatorio(bool exibirNotas); // Sobrecarga
};

#endif