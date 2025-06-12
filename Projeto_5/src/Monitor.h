#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"
#include <vector>

class Monitor : public Aluno, public Professor {
private:
    std::vector<std::string> disciplinasMonitoradas;

public:
    Monitor(std::string nome, std::string email, std::string matricula, std::string curso, std::string area);

    void adicionarDisciplinaMonitorada(const std::string& disciplina);

    void listarDisciplinasMonitoradas() const;

    void gerarRelatorio() const override;
};

#endif
