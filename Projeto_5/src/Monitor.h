#ifndef MONITOR_H
#define MONITOR_H
#include "Aluno.h"
#include "Professor.h"
#include <vector>
#include <string>
class Monitor : public Aluno, public Professor {
private:
    std::vector<std::string> disciplinasMonitoradas;
public:
    Monitor() {}
    Monitor(std::string n, std::string e, std::string t) : Aluno(n,e,t,"",""), Professor(n,e,t,"") {}
    void listarDisciplinasMonitoradas();
};
#endif
