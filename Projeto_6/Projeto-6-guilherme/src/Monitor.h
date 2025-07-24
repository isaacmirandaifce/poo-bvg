#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"
#include <string>

class Monitor : public Aluno, public Professor {
public:
    Monitor(std::string nome, std::string email, std::string senha,
            std::string matricula, std::string curso, std::string area);

    void gerarRelatorio() const override;
};

#endif