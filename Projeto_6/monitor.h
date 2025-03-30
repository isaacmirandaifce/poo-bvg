#ifndef MONITOR_H
#define MONITOR_H

#include "../usuario/UsuarioAutenticavel.h"  // Corrigido caminho relativo
#include "../relatorio/Relatorio.h"          // Corrigido caminho relativo
#include <vector>

class Monitor : public UsuarioAutenticavel, public Relatorio {
private:
    std::vector<std::string> disciplinasMonitoradas;

public:
    Monitor(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso, const std::string& areaDeAtuacao, const std::string& senha);
    void adicionarDisciplinaMonitorada(const std::string& disciplina);
    void gerarRelatorio() const override;
    ~Monitor() {}
};

#endif