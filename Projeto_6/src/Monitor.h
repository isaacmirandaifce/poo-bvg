#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Relatorio.h"
#include <vector>
#include <string>

class Monitor : public Aluno {
private:
    std::vector<std::string> disciplinasMonitoradas;
    Relatorio relatorio;

public:
    Monitor();
    Monitor(const std::string& nome, const std::string& email, const std::string& senha,
            const std::string& matricula, const std::string& curso,
            const std::vector<std::string>& disciplinasMonitoradas);

    bool autenticar(const std::string& senha) const override;
    void exibirInformacoes() const override;
    void gerarRelatorio() const;
};

#endif
