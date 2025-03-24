#ifndef MONITOR_H
#define MONITOR_H
#include "Aluno.h"
#include "Professor.h"

class Monitor : public Aluno, public Professor {
public:
    Monitor(string n, string e, string s, string m, string c, string a) : Aluno(n, e, s, m, c), Professor(n, e, a) {}
    void gerarRelatorio() const override;
};

#endif // MONITOR_H
