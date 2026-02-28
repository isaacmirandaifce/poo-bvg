#ifndef MONITOR_H
#define MONITOR_H

#include "aluno.h"
#include <vector>

class Monitor : public Aluno {
private:
    std::vector<std::shared_ptr<Disciplina>> disciplinasMonitoradas; // Disciplinas que o monitor ensina

public:
    Monitor(const std::string& nome, const std::string& email, const std::string& tipo, const std::string& curso);

    // Adicionar uma disciplina monitorada
    void adicionarDisciplinaMonitorada(const std::shared_ptr<Disciplina>& disciplina);

    // Sobrescrita do método para gerar o relatório do monitor
    void gerarRelatorio() const override;
};

#endif // MONITOR_H
