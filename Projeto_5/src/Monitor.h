#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"

class Monitor : public Aluno, public Professor {
private:
    std::vector<std::string> disciplinasMonitoradas;

public:
    Monitor();
    Monitor(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso, const std::string& areaDeAtuacao);

    void adicionarDisciplina(const std::string& disciplina); // Resolve ambiguidade
    void adicionarDisciplinaMonitorada(const std::string& disciplina);
    virtual void gerarRelatorio() const override;
};

#endif // MONITOR_H
