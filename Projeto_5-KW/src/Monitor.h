#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"
#include <vector>

class Monitor : public Aluno, public Professor {
private:
    std::vector<std::string> disciplinasMonitoradas;
public:
    Monitor(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso, const std::string& area);

    void adicionarDisciplinaMonitorada(const std::string& disciplina);

    void gerarRelatorio() const override; // sobrescrita

    void listarDisciplinasMonitoradas() const; // método adicional
};

#endif