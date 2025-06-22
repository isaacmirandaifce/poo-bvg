#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"
#include <vector>

class Monitor : public Aluno, public Professor {
private:
    vector<string> disciplinasMonitoradas;

public:
    Monitor(string n, string e, string m, string c, string area);

    void adicionarDisciplinaMonitorada(string d);
    void gerarRelatorio() const override;
};

#endif
