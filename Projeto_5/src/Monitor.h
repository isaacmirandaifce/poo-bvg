#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"


class Monitor : public Aluno, public Professor {
private:
    std::vector<std::string> disciplinasMonitoradas;

public:
    Monitor(std::string n, std::string e, std::string t, std::string mat, std::string cur, std::string area, std::vector<std::string> discMin);
    virtual ~Monitor() {}

    void adicionarMonitoria(std::string disc);
    void listarDisciplinasMonitoradas();
    

    void gerarRelatorio() override; 
};

#endif