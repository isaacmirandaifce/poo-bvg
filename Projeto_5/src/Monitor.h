#ifndef MONITOR_H
#define MONITOR_H

#include <string>
#include <vector>
#include "Aluno.h"
#include "Professor.h"

// Heranca multipla: Monitor e simultaneamente um Aluno e um Professor.
// Aluno e Professor herdam Usuario virtualmente para existir um unico
// subobjeto Usuario dentro de Monitor (evita ambiguidade do diamante).
class Monitor : public Aluno, public Professor {
private:
    std::vector<std::string> disciplinasMonitoradas;

public:
    Monitor();
    Monitor(std::string nome, std::string email, std::string matricula, std::string curso,
            std::string areaDeAtuacao);

    void adicionarDisciplinaMonitorada(const std::string& disciplina);
    void listarDisciplinasMonitoradas() const;

    // Sobrescrita: combina os relatorios de Aluno e Professor
    void gerarRelatorio() const override;
};

#endif // MONITOR_H
