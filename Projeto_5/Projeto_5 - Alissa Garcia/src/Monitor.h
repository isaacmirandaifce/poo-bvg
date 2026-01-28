#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"
#include <vector>
#include <string>

using namespace std;

class Monitor : public Aluno, public Professor {
private:
    vector<string> disciplinasMonitoradas;

public:
    Monitor();
    Monitor(string nome, string email, string tipo,
            string matricula, string curso,
            string areaDeAtuacao);

    void adicionarDisciplinaMonitorada(string disciplina);
    void listarDisciplinasMonitoradas();

    void gerarRelatorio() override;
};

#endif
