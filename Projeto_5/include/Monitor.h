#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"

class Monitor : public Aluno, public Professor {
private:
    vector<string> disciplinasMonitoradas;

public:
    Monitor(const string& nome, const string& email, const string& matricula, const string& curso,
            const string& areaDeAtuacao, const vector<string>& disciplinasMinistradas, const vector<string>& disciplinasMonitoradas);

    // Relatório específico para Monitores
    void gerarRelatorio() const override;
};

#endif
