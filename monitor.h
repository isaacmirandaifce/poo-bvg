#ifndef MONITOR_H
#define MONITOR_H

#include "aluno.h"
#include "professor.h"
#include <vector>
#include <string>

class monitor : public aluno, public professor {
private:
    std::vector<std::string> disciplinasMonitoradas;

public:
    monitor();
    monitor(std::string nome, std::string email, std::string matricula, std::string curso, std::string areaDeAtuacao);

    void adicionarDisciplinaMonitorada(std::string disciplina);

    
    void adicionarDisciplina(std::string disciplina) {
        aluno::adicionarDisciplina(disciplina);
    }

    void gerarRelatorio() const override;
};

#endif

