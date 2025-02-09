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
    // Construtor
    Monitor(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso,
            const std::string& areaDeAtuacao, const std::vector<std::string>& disciplinasMinistradas, const std::vector<std::string>& disciplinasMonitoradas);

    // Métodos
    void gerarRelatorio() const;
};

#endif // MONITOR_H