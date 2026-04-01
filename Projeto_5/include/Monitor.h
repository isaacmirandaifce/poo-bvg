#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"

class Monitor : public Aluno, public Professor {
    private:
    vector<string> disciplinasMonitoradas;

    public:
    Monitor(string nome, string email, string matricula, string curso, string area);

    void adicionarDisciplinaMonitorada(string disciplina);
    void listarMonitorias () const;
};

#endif