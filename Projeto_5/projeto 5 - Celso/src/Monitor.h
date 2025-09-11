#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"
#include <vector>

class Monitor : public Aluno, public Professor {
private:
    std::vector<std::string> disciplinasMonitoradas;

public:
    // Construtor padrão
    Monitor();

    // Construtor parametrizado
    Monitor(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso, const std::string& areaDeAtuacao);

    // Método para adicionar disciplinas monitoradas
    void adicionarDisciplinaMonitorada(const std::string& disciplina);

    // Sobrescrita do método gerarRelatorio
    void gerarRelatorio() const override;
};

#endif // MONITOR_H