#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"

// Classe com Herança Múltipla
class Monitor : public Aluno, public Professor {
public:
    Monitor(std::string nome, std::string email, std::string matricula, std::string curso, std::string area);

    void gerarRelatorio() override;
};

#endif
