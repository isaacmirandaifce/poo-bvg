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
    Monitor(const std::string& nome, const std::string& matricula, const std::string& curso, const std::string& email, 
            const std::string& areaDeAtuacao, const std::vector<std::string>& disciplinas, 
            const std::vector<std::string>& disciplinasMonitoradas);

    void gerarRelatorio() const override;
    void listarDisciplinasMonitoradas() const;
};

#endif // MONITOR_H
