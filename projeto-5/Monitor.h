#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"
#include <vector>
#include <string>

class Monitor : public Aluno, public Professor
{
    private:
        std::vector<std::string> disciplinasMonitoradas;

    public:
        Monitor(std::string nome, std::string email, std::string matricula, std::string curso, std::string areaDeAtuacao);

        void adicionarDisciplinaMonitorada(const std::string& disciplina);

        void listarDisciplinasMonitoradas();

        // Sobrescreve para resolver a ambiguidade de herança
        void gerarRelatorio() override;
};

#endif
