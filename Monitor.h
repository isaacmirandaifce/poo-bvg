#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"
#include <vector>
#include <iostream>

class Monitor : public Aluno, public Professor {
private:
    std::vector<std::string> disciplinasMonitoradas;

public:
    Monitor(const std::string& nome, const std::string& email,
            const std::string& matricula, const std::string& curso,
            const std::vector<std::string>& disciplinasAluno,
            const std::string& areaDeAtuacao, const std::vector<std::string>& disciplinasProfessor,
            const std::vector<std::string>& disciplinasMonitoradas);

    void listarDisciplinasMonitoradas() const;

    void gerarRelatorio() const override;
};

#endif // MONITOR_H
