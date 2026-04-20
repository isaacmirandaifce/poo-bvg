#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"

class Monitor : public Aluno, public Professor {
public:
    Monitor();
    void listarDisciplinasMonitoradas();
};

#endif
