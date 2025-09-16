#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"

class Monitor : public Aluno, public Professor {
public:
    Monitor();
    Monitor(string nome, string email, string curso, int matricula, string disciplina, string titulacao);
    void gerarRelatorio() const override;
};

#endif
