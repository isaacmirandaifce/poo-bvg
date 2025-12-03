#ifndef MONITOR_H
#define MONITOR_H

#include "aluno.h"
#include "professor.h"

// Declaração da classe Monitor que herda de Aluno e Professor
class Monitor : public Aluno, public Professor {
private:
    std::vector<std::string> disciplinasMonitoradas;

public:
    Monitor(std::string nome, std::string email,
            std::string matricula, std::string curso,
            std::string area);

    void adicionarDisciplinaMonitorada(std::string d);

    void gerarRelatorio() const override;
};

#endif
