#ifndef MONITOR_H
#define MONITOR_H

#include "../Aluno/Aluno.h"
#include "../Professor/Professor.h"

class Monitor : public Aluno, public Professor {
public:
    Monitor();
    Monitor(string nome, string email, string tipo, string matricula, string curso, vector<string> disciplinasAluno,
            string areaDeAtuacao, vector<string> disciplinasMinistradas);
    void gerarRelatorio() override;
};

#endif