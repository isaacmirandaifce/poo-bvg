#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"

class Monitor : public Aluno, public Professor {
private:
    std::vector<std::string> disciplinasMonitoradas;

public:
    // Construtores
    Monitor();
    Monitor(const std::string& nome, const std::string& email, const std::string& matricula,
            const std::string& curso, const std::string& areaDeAtuacao);

    // Métodos
    void adicionarDisciplinaMonitorada(const std::string& disciplina);
    void gerarRelatorio() const override;
};

#endif // MONITOR_H
