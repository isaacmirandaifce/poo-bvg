#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"

class Monitor : public Aluno, public Professor {
public:
    Monitor(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso, const std::string& areaDeAtuacao);

    void listarDisciplinasMonitoradas() const;
    void gerarRelatorio() const override;
};

#endif // MONITOR_H
