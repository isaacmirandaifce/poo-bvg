#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"
#include <vector>

class Monitor : public Aluno, public Professor {
private:
    std::vector<std::string> disciplinasMonitoradas;

public:
    Monitor();
    Monitor(const std::string& nome,
            const std::string& email,
            const std::string& matricula,
            const std::string& curso,
            const std::vector<std::string>& disciplinasCursadas,
            const std::string& areaDeAtuacao,
            const std::vector<std::string>& disciplinasMinistradas,
            const std::vector<std::string>& disciplinasMonitoradas);

    void listarDisciplinasMonitoradas() const;

    // pode sobrescrever também 
    void gerarRelatorio() const override;
};

#endif
