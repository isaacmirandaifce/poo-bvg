#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"
#include <vector>

class Monitor : public Aluno, public Professor {
private:
    std::vector<std::string> disciplinasMonitoradas;

public:
    Monitor(const std::string& nome, const std::string& email,
            const std::string& matricula, const std::string& departamento);

    // Sobrescrita do método virtual para resolver ambiguidade
    void exibirInformacoes() const override;

    void adicionarDisciplinaMonitorada(const std::string& codigoDisciplina);
    void listarDisciplinasMonitoradas() const;
};

#endif // MONITOR_H